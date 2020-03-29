createproj(){
	CURRENTDIR=$(pwd)
	mkdir .eclipse
	pushd .eclipse
	cmake $CURRENTDIR -G"Eclipse CDT4 - Unix Makefiles" && echo Done. Please import the project in $CURRENTDIR/.eclipse;
	popd
}

case "$1" in
	"")
		[ -f .eclipse ] || createproj
	;;
esac
