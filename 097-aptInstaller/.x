build(){
	./build-app.sh
	./build-image.sh
	./test-image.sh
	./launch-app.sh
}
case "$1" in
	 e) vi -p Dockerfile {,lib/,src/,test/,include/}CMakeLists.txt lib/helloworld_lib.cpp src/helloworld.cpp test/helloworld_test.cpp include/helloworld.hpp .x; ;;
	"") build; ;;
esac
