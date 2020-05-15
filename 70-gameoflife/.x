execute(){
	./app r-pentomino.matrix
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
		rm -f app
		[ -f app ] || build;
		execute
	;;
	d)	# Debug
		debug
	;;
	e)
		vi -p app.cpp CMakeLists.txt
		rm -f app
		build;
		execute;
	;;
esac
