execute(){
	sleep 1;
	jar xvf Subscriber.jar Subscriber.class
	java -cp jeromq-0.4.3.jar:. Subscriber &
	./publisher "{Message:HelloWorld}"
	kill $(ps fax|grep Subscriber|awk '{print $1}') &>/dev/null
}
build(){
	[ -d build/ ] && {
		pushd build &> /dev/null;
	} || {
		mkdir build;
		pushd build &> /dev/null;
		cmake .. -Wdev;
	}
	make -j8; STATUS=$?
	popd &> /dev/null;
	[ $STATUS == 0 ] && echo [100%] $(ls -l publisher) || echo [ERROR] Compilation error.
}
case "$1" in
	"")
		[ -f app ] || build;
		execute
	;;
	e)
		vi -O subscriber.cpp publisher.cpp
		build;
		execute;
	;;
esac
