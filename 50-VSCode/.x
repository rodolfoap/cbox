[ -f ~/.config/Code/User/settings.json ] && { echo Please remove ~/.config/Code/User/settings.json; exit; }
execute(){
	./app
}
checkconf(){
	code --install-extension ms-vscode.cmake-tools
	code --install-extension ms-vscode.cpptools
	code --install-extension takanotume24.pdf
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
# Check Config
c)	checkconf
;;
# Build
b)	build
;;
# Open editor
e)	code .
;;
esac
