#include "solid.h"
#include "factorial.h"

/**
 * The main function
 * @mainpage
 * @author RodolfoAP <rodolfoap@gmail.com>
 * @returns The exit status.
 */
int main(void) {
    Solid solid;
    Factorial factorial;
    solid.setName("solid0");
    std::cerr << "The solid name is: " << solid.getName() << std::endl;
    std::cerr << "Factorial of 4 is: " << factorial.get(4) << std::endl;
    return 0;
}
