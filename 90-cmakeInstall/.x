install(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	sudo make install
	popd &> /dev/null;
	sudo ldconfig
}
case "$1" in
	e)
		vi -p helloworld.cpp include/helloworld.hpp CMakeLists.txt
		install
	;;
	"")
		install;
	;;
esac
