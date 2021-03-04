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
#	[ $STATUS == 0 ] && echo [100%] $(ls -l libhello.so) || echo [ERROR] Compilation error.
}
case "$1" in
	"")
		[ -f libhello.so ] || build;
		execute
	;;
	e)
		vi -p hello.cpp app.py CMakeLists.txt
		build;
		execute;
	;;
esac
