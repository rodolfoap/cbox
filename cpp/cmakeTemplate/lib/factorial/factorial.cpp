#include "factorial.h"
#include <iostream>

/**
 * Copies bytes from a source memory area to a destination memory area,
 * where both areas may not overlap.
 * @param[in] x	The input.
 * result	The result.
 */
int Factorial::get(int x){
    unsigned long long factorial = 1;
    for(int i = 1; i <=x; ++i) factorial *= i;
    return factorial;
}
