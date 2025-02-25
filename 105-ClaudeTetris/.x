case "$1" in
e)	vi ./main.cpp
;;
"")	./build.bash;
	./opticalflow
;;
esac
