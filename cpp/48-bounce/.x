execute(){
	./app
}
debug(){
	nemiver app
}
build(){
	rm -f app
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
	b)
		build;
	;;
	e)
		vi -p app.cpp CMakeLists.txt
		build;
		execute;
	;;
esac
