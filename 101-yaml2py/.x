execute(){
	echo 'username: nonino' > config.yaml
	echo -n 'password: dedalo' >> config.yaml
	echo === config.yaml ===; cat config.yaml; echo; echo ===================;
	./app
	echo === config.yaml ===; cat config.yaml; echo; echo ===================;
}
build(){
	export VERSION=7.18.0
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
case "$1" in
	"")
		[ -f app ] || build;
		execute
	;;
	e)
		vi -p app.cpp .x conanfile.py CMakeLists.txt
		rm -f app
		build;
		execute;
	;;
esac
