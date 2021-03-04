execute(){
	./app
	echo -e "=== app.cpp output ===\n" $?
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?

	make app.i;
	mv CMakeFiles/app.dir/app.cpp.i ..
	make app.s;
	mv CMakeFiles/app.dir/app.cpp.s ..
	make; STATUS=$?

	popd &> /dev/null;

	echo === app.cpp.i ===
	cat app.cpp.i|grep -v '^\x*$'
	echo === app.cpp.s ===
	cat app.cpp.s
}
case "$1" in
	"")
		[ -f app ] || build;
		execute
	;;
	e)
		vi -p app.cpp CMakeLists.txt
		build;
		execute;
	;;
esac
