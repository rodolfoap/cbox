execute(){
	export VLC_PLUGIN_PATH=/usr/lib/x86_64-linux-gnu/vlc/plugins/
	./app PETS09-S2L1.mp4
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
