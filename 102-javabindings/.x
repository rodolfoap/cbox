execute(){
	./buildall.sh
}
case "$1" in
e)	vi -p ./buildall.sh Bindings.?pp eu/acme/bindings/Bindings.java
	;;
"")	execute
	;;
esac

