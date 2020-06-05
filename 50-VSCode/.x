[ -f ~/.config/Code/User/settings.json ] && { echo Please remove ~/.config/Code/User/settings.json; exit; }
execute(){
	./app
}
checkconf(){
cat << EOF |base64 -d|bunzip2 -c > .vscode/settings.json
QlpoOTFBWSZTWQuv19EAAN3fgAAwUGehUA8gzgS/79/6MAESEGiNJ6mij8Cp6T1P0poAGnqHqekCU0VT9Mqfqm9JPSGgZAG1AwaQwADRpoAyaA0GQGggbKYNe0kN+pl9V9Yxu48Y2lJhN7FBAJkehLP2
IfSndD0W5V3LFEW/IJKljwScZp47DbTZa1L6wNwwNdF36hHz8ReIRL56U1C5NpkHaj82Y/1oLMLMSVuw5OIW5lJ+5wmYSZrAg5EjrLjdddxbj14jDGwk0jqR1C254Zi2geRyCHEEz9KmgEDpG9MnfbO1
osr6kjA7gYfsxW8HISu2NpHuccUzvcEKhTIl8ozE6nTLlA6+lJjvyoZcxouIRpwuz4Stqg7i5eMO04LylSXbERbJDeXOSvrgU1aK9GbM97ty5f4u5IpwoSAXX6+i
EOF
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
