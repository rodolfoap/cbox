execute(){
	./publisher
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
	[ $STATUS == 0 ] && echo [100%] $(ls -l publisher) || echo [ERROR] Compilation error.
}
case "$1" in
	"")
		[ -f app ] || build;
		execute
	;;
	e)
		vi -O subscriber.cpp publisher.cpp
		build;
		execute;
	;;
esac
