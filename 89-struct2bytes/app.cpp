#include <iostream>
#include <cstring>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;
#define log(text)(std::cerr<<text<<std::endl)

struct Register {
    float yaw;
    float pitch;
    float roll;
};

int main() {
    Register source( {87.96, -114.58, 100.50} );

    // Get Size
    size_t size=sizeof(source);
    log("Size:"<<size);

    // To bytes
    char b[size];
    memcpy(b, &source, size);

    // To Struct
    Register target;
    memcpy(&target, b, sizeof(target));
    log("Register: ("<<target.yaw<<", "<<target.pitch<<", "<<target.roll<<")");
}
