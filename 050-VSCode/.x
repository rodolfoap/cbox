execute(){ ./app; }
checkconf(){
	tar xvfj .vscode.tbz2
	for a in $(grep -v '[][{}]' .vscode/extensions.json|cut -f2 -d'"'); do code --install-extension --force $a; done
	[ -f ~/.config/Code/User/settings.json ] && { echo Please remove ~/.config/Code/User/settings.json; }
	cp -v .vscode/keybindings.json ~/.config/Code/User/keybindings.json
	cp -v .vscode/settings.json    ~/.config/Code/User/settings.json
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
saveconf(){ tar cvfj .vscode.tbz2 .vscode/ .x .k README.md; cp -v .vscode.tbz2 ~/git/home/; }
case "$1" in
s)	saveconf;  ;; # Save Config
c)	checkconf; ;; # Check Config
b)	build;     ;; # Build
e)	code .;    ;; # Edit with VSCode
"")	[ -f app ] || build; execute; ;; # Exec
esac
