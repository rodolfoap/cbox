execute(){
	echo === C++:; echo
	./app
	echo === Python3:; echo
	./app.py
	echo
}
build(){
	[ -d build/ ] && {
		pushd build &> /dev/null;
	} || {
		mkdir build;
		pushd build &> /dev/null;
		cmake .. -Wdev;
	}
	make -j8; STATUS=$?
	popd &> /dev/null;
}
case "$1" in
	"")
		[ -f libhello.so ] || build;
		execute
	;;
	e)
		vi -p hello_c.cpp include/hello_c.hpp hello.cpp include/hello.hpp app.cpp app.py app_wrapper.py CMakeLists.txt
		build;
		execute;
	;;
esac
