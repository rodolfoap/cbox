execute(){
	./app.py
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
		vi -p hello.cpp include/hello.hpp hello_c.cpp include/hello_c.hpp app.cpp app.py app_wrapper.py CMakeLists.txt
		build;
		execute;
	;;
esac
