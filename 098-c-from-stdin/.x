execute(){
	./app.bash
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
