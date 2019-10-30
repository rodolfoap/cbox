VIDFILE=../vid/003-ExceptionsBasics.mp4

case "$1" in
e)
	vi -p *.cpp *.h
;;
p)
	{	sleep 3; echo acting...;
		/usr/bin/wmctrl -a MPlayer -e 0,1280,0,1280,800;
		/usr/bin/wmctrl -a MPlayer -b toggle,above;
	} &
	mplayer $VIDFILE
;;
'')
	(mkdir -p build; cd build; cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..; make -j8 && echo && ./app;)
;;
esac
