execute(){
	./pub "tcp://*:5557"
}
execsub(){
	./sub "tcp://127.0.0.1:5557"
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
		vi -p 	sub.cpp pub.cpp icarrier.cpp message.cpp functions.cpp \
			include/icarrier.hpp include/message.hpp include/functions.hpp
		rm -f pub sub
		build;
		execute;
	;;
	s)
		execsub;
	;;
	b)
		build;
	;;
	"")
		[ -f pub ] && [ -f sub ] || build;
		execute
	;;
esac
