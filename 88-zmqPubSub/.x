execute(){
	./vrsink
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
		vi -p vrsink.cpp worker.cpp message.cpp functions.cpp include/message.hpp include/functions.hpp
		rm -f worker vrsink
		build;
		execute;
	;;
	b)
		build;
	;;
	"")
		[ -f worker ] && [ -f vrsink ] || build;
		execute
	;;
esac
