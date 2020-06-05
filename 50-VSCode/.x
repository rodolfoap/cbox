execute(){
	./app
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
case "$1" in
# Execute
"")	[ -f app ] || build;
	execute
;;
# Build
b)	build
;;
# Open editor
e)	code .
;;
esac
