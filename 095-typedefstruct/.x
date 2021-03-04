execute(){
	./app
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake 3 .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
case "$1" in
	"")
		[ -f app ] || build;
		execute
	;;
	e)
		vi -p app.c CMakeLists.txt
		rm -f app
		build;
		execute;
	;;
esac
