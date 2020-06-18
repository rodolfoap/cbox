execute(){
	./server
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
case "$1" in
	e)
		vi -p server.cpp message.cpp functions.cpp include/message.hpp include/functions.hpp
		rm -f server
		build;
		execute;
	;;
	b)
		build;
	;;
	"")
		[ -f worker ] && [ -f server ] || build;
		execute
	;;
esac
