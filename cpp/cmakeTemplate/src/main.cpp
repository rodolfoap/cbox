#include "solid.h"
#include "factorial.h"

/**
 * The main function
 * return The exit status.
 * @mainpage
 * @author RodolfoAP <rodolfoap@gmail.com>
 */
int main(void) {
    Solid solid;
    Factorial factorial;
    solid.setName("solid0");
    std::cerr << "The solid name is: " << solid.getName() << std::endl;
    std::cerr << "Factorial of 4 is: " << factorial.get(4) << std::endl;
    return 0;
}
