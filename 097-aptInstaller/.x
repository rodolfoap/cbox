build(){
	echo "==============================================================="
	./build-app.sh
	echo "==============================================================="
	./build-image.sh
	echo "==============================================================="
	./test-image.sh
	echo "==============================================================="
	./launch-app.sh
	echo "==============================================================="
}
case "$1" in
	 e) vi -p Dockerfile {,lib/,src/,test/,include/}CMakeLists.txt lib/helloworld_lib.cpp src/helloworld.cpp test/helloworld_test.cpp include/helloworld.hpp .x; ;;
	 a) ./build-app.sh; ;;
	"") build; ;;
esac
