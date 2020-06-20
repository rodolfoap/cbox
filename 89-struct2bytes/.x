execute(){
	./app "Hello, World!"
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
case "$1" in
	"")
		[ -f app ] || build;
		execute
	;;
	e)
		vi -p app.cpp CMakeLists.txt
		rm -f app
		build;
		execute;
	;;
esac
