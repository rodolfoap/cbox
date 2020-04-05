execute(){
	./parsekml points.kml|head -3 > points.dat
	./ppicker crowd.jpg points.dat points.tpl
}
debug(){
	nemiver ppicker
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
	[ $STATUS == 0 ] && echo [100%] $(ls -l ppicker) || echo [ERROR] Compilation error.
}
case "$1" in
	"")
		[ -f ppicker ] || build;
		execute
	;;
	d)	# Debug
		debug
	;;
	e)
		vi -p main.cpp window.cpp window.h form.cpp form.h functions.cpp points.tpl CMakeLists.txt
		build;
		execute;
	;;
esac
