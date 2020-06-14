execute(){
	mono client.exe
}
build(){
	mcs -out:client.exe -r:ZeroMQ.dll client.cs # -lib:/usr/local/zmq/bin/Release/
}
case "$1" in
	e)
		vi client.cs
		rm -f client.exe
		build
		execute
	;;
	b)
		build;
	;;
	"")
		[ -f client.exe ] || build;
		execute
	;;
esac
