execute(){
	./app
	echo -e "=== app.cpp output ===\n" $?
}
build(){
	[ -d build/ ] && {
		pushd build &> /dev/null;
	} || {
		mkdir build;
		pushd build &> /dev/null;
		/bin/cmake ..;
	}
	make app.i;
	mv CMakeFiles/app.dir/app.cpp.i ..
	make app.s;
	mv CMakeFiles/app.dir/app.cpp.s ..
	make; STATUS=$?
	popd &> /dev/null;
	[ $STATUS == 0 ] && echo [100%] $(ls -l app) || echo [ERROR] Compilation error.
	echo === app.cpp.s ===
	cat app.cpp.s
	echo === app.cpp.i ===
	cat app.cpp.i
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
