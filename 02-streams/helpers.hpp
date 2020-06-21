#ifndef HELPERS_H
#define HELPERS_H

#include <thread>
#include <cstddef>
#include <stdint.h>
#include <iostream>            

#define print(text)(std::cerr<<text<<std::endl)
#define printdot std::cerr<<'.'
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl
#define sleep(ms){std::this_thread::sleep_for(std::chrono::milliseconds(ms));}

#endif
