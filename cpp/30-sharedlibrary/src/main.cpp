#include <iostream>
#include "factorial.h"

int main(void) {
    Factorial factorial;
    std::cerr << "Factorial of 4 is: " << factorial.get(4) << std::endl;
    return 0;
}
