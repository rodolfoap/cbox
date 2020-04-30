execute(){
	echo abcdefghijklm nopqrstuvwxyz ABCDEFGHIJKLM NOPQRSTUVWXYZ 1234567890|./rot13
	echo nopqrstuvwxyz abcdefghijklm NOPQRSTUVWXYZ ABCDEFGHIJKLM 1234567890|./rot13
}
build(){
	gcc app.cpp -o rot13
}
case "$1" in
	"")
		build;
		execute
	;;
	e)
		vi -p app.cpp
		build;
		execute;
	;;
esac
