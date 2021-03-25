localinstall(){
set -x
	source ./VERSION
	export VERSION
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=release
	make -j$(nproc)
	#sudo make install
	popd &> /dev/null;
	sudo ldconfig
}
remoteinstall(){
set -x
	CONAN_PASSWORD=$(cat /home/rodolfoap/.gitlab.com_token) conan user rodolfoap -r gitlab -p
	conan create . rodolfoap+ciexample/stable -r gitlab
	# Which is equivalent to:
	#	conan export . rodolfoap+ciexample/stable
	#	conan install -r gitlab helloworld/${VERSION}@rodolfoap+ciexample/stable --build=helloworld
	conan upload helloworld/${VERSION}@rodolfoap+ciexample/stable -r gitlab

set +x
}
case "$1" in
	e)
		vi -p conanfile.py src/helloworld.cpp include/helloworld.hpp CMakeLists.txt src/CMakeLists.txt
		localinstall
	;;
	r)	remoteinstall;
	;;
	"")
		localinstall;
	;;
esac
