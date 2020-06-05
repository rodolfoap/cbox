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
# Check
c)	meld ~/.config/Code/User/settings.json .vscode/settings.json
;;
# Open editor
e)	code .
;;
esac
