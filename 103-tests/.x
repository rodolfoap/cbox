execute(){
	./app
	cd build
	make test # or just ctest
}
debug(){
	nemiver app
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
	[ $STATUS == 0 ] && echo [100%] $(ls -l app) || echo [ERROR] Compilation error.
}
case "$1" in
	"")
		[ -f app ] || build;
		execute
	;;
	d)	# Debug
		debug
	;;
	e)
		vi -p test_app.cpp app.cpp reverse.hpp reverse.cpp CMakeLists.txt
		build;
		execute;
	;;
esac
