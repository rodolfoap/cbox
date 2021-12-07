execute(){
	./app.bash
	./a.out
}
case "$1" in
	"")
		execute
	;;
	e)
		vi -p app.bash
		execute;
	;;
esac
