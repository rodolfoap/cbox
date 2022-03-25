execute(){
cat << EOF > config.yaml
username: nonino
password: dedalo
EOF
	echo; echo === config.yaml ===; sed 's/^/\t/' config.yaml; echo; echo ===================;
	./app
	echo; echo === config.yaml ===; sed 's/^/\t/' config.yaml; echo; echo ===================;
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
		vi -p app.cpp conanfile.txt CMakeLists.txt
		rm -f app
		build;
		execute;
	;;
esac
