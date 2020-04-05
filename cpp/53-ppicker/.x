execute(){
	./parsekml points.kml > points.dat
	./app crowd.jpg points.dat points.tpl
}
debug(){
	nemiver app
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
	e)
		vi -p app.cpp window.cpp window.h form.cpp form.h functions.cpp points.tpl CMakeLists.txt
		build;
		execute;
	;;
esac
