case $1 in
	d|doc)	pushd build &> /dev/null
		make doxygen
		make doxygen-factorial
		make doxygen-main
		popd &> /dev/null
	;;
	*) 	rm --interactive=never -rf build/;
		mkdir build;
		pushd build &> /dev/null
		cmake ..;
		make
		make doxygen
		make doxygen-factorial
		make doxygen-main
		popd &> /dev/null
	;;
esac
