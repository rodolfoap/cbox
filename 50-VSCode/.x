execute(){ ./app; }
checkconf(){
	tar xvfj .vscode.tz
	code --install-extension ms-vscode.cmake-tools
	code --install-extension ms-vscode.cpptools
	code --install-extension takanotume24.pdf
	[ -f ~/.config/Code/User/settings.json ] && { echo Please remove ~/.config/Code/User/settings.json; }
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
saveconf(){ tar cvfj .vscode.tz .vscode/; }
case "$1" in
s)	saveconf;  ;; # Save Config
c)	checkconf; ;; # Check Config
b)	build;     ;; # Build
e)	code .;    ;; # Edit with VSCode
"")	[ -f app ] || build; execute; ;; # Exec
esac
