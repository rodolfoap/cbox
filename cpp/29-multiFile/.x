case "$1" in
e)
	vi -p *.cpp *.h
;;
'')
	(mkdir -p build; cd build; cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..; make -j8 && /bin/rc -J . && echo && ./app;)
;;
esac
