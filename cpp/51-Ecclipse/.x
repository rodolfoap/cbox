createproj(){
	mkdir .eclipse
	pushd .eclipse
	cmake .. \
		-G"Eclipse CDT4 - Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=Debug \
		-DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE \
		&& \
		echo Done. Please import the project in $(pwd);
	popd
}

case "$1" in
	"")
		[ -f .eclipse ] || createproj
	;;
esac
