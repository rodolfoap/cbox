execute(){
	rm -f rot13
	gcc -Wno-implicit-int -Wno-implicit-function-declaration rot13.c -o rot13
	echo ABCDEFGHIJKLM NOPQRSTUVWXYZ abcdefghijklm nopqrstuvwxyz 1234567890|./rot13
#	echo NOPQRSTUVWXYZ ABCDEFGHIJKLM nopqrstuvwxyz abcdefghijklm 1234567890|./rot13
}
case "$1" in
	"")
		execute
	;;
	e)
		vi -p rot13.c
		execute;
	;;
esac
