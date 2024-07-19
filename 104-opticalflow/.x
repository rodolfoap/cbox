case "$1" in
e)	/bin/code .		&>/dev/null
	i3-msg workspace 8	&>/dev/null
;;
"")	./build.bash;
	./opticalflow
;;
esac
