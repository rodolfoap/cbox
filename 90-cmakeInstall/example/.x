execute(){
	/usr/local/bin/helloworld
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	sudo make install
	popd &> /dev/null;
}
case "$1" in
	"")
		[ -f helloworld ] || build;
		execute
	;;
	e)
		vi -p helloworld.cpp CMakeLists.txt
		rm -f helloworld
		build;
		execute;
	;;
esac
