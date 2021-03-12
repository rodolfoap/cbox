execute(){
	./app.py
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
}
case "$1" in
	"")
		[ -f libholder.so ] || build;
		execute
	;;
	e)
		vi -p secbroker.cpp include/secbroker.hpp ./holder.cpp include/holder.hpp ./holder.py ./app.py CMakeLists.txt
		build;
		execute;
	;;
esac


