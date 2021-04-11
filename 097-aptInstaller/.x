build(){
	./build-app.sh
	# sudo make install
	sudo dpkg -i build/helloworld-*-linux.deb
	dpkg-query -L helloworld
	helloworld
	sudo dpkg -r helloworld
}
case "$1" in
	e)
		vi -p {,lib/,src/,test/,include/}CMakeLists.txt lib/helloworld_lib.cpp src/helloworld.cpp test/helloworld_test.cpp include/helloworld.hpp .x
	;;
	"")
		build;
	;;
esac
