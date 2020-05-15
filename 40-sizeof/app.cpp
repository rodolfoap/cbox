#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

char* Demangle(const char* Object) {
    int Status;
    char* RealName;
    RealName=abi::__cxa_demangle(Object, 0, 0, &Status);
    return RealName;
}

int main() {
	auto n01=23;		// int 				(nothing)
	auto n02=23U;		// unsigned int: 		[uU]
	auto n03=23L;		// long:			[lL]
	auto n04=23ul;		// unsigned long:		[uU][lL] or permutation
	auto n05=23ll;		// long long:			[lL][lL]
	auto n06=23ull;		// unsigned long long:		[uU][lL][lL] and permutations
	auto n07=23.01F;	// float:			.[0-9]+[fF]
	auto n08=23.01L;	// long double:			.[0-9]+[lL]
	std::cerr<<"n01 ["<<sizeof(n01)<<"]:\t"<<n01<<"\t"<<Demangle(typeid(n01).name())<<std::endl;
	std::cerr<<"n02 ["<<sizeof(n02)<<"]:\t"<<n02<<"\t"<<Demangle(typeid(n02).name())<<std::endl;
	std::cerr<<"n03 ["<<sizeof(n03)<<"]:\t"<<n03<<"\t"<<Demangle(typeid(n03).name())<<std::endl;
	std::cerr<<"n04 ["<<sizeof(n04)<<"]:\t"<<n04<<"\t"<<Demangle(typeid(n04).name())<<std::endl;
	std::cerr<<"n05 ["<<sizeof(n05)<<"]:\t"<<n05<<"\t"<<Demangle(typeid(n05).name())<<std::endl;
	std::cerr<<"n06 ["<<sizeof(n06)<<"]:\t"<<n06<<"\t"<<Demangle(typeid(n06).name())<<std::endl;
	std::cerr<<"n07 ["<<sizeof(n07)<<"]:\t"<<n07<<"\t"<<Demangle(typeid(n07).name())<<std::endl;
	std::cerr<<"n08 ["<<sizeof(n08)<<"]:\t"<<n08<<"\t"<<Demangle(typeid(n08).name())<<std::endl;

	auto s01= "Hello";	//     char const*
	auto s02=L"Hello";	//  wchar_t const*
	auto s03=u"Hello";	// char16_t const*
	auto s04=U"Hello";	// char32_t const*
	std::cerr <<s01<<"\t"<<Demangle(typeid(s01).name())<<std::endl;
	std::wcerr<<s02<<"\t"<<Demangle(typeid(s02).name())<<std::endl;
	std::wcerr<<s03<<"\t"<<Demangle(typeid(s03).name())<<std::endl;
	std::wcerr<<s04<<"\t"<<Demangle(typeid(s04).name())<<std::endl;

	std::cerr
		<<"sizeof(char):        "<<sizeof(char)		<<std::endl 	// 1
		<<"sizeof(short):       "<<sizeof(short)	<<std::endl 	// 2
		<<"sizeof(int):         "<<sizeof(int)		<<std::endl 	// 4
		<<"sizeof(long):        "<<sizeof(long)		<<std::endl 	// 8
		<<"sizeof(long long):   "<<sizeof(long long)	<<std::endl 	// 8
		<<"sizeof(float):       "<<sizeof(float)	<<std::endl 	// 4
		<<"sizeof(double):      "<<sizeof(double)	<<std::endl 	// 8
		<<"sizeof(long double): "<<sizeof(long double)	<<std::endl 	// 16
		<<"sizeof(bool):        "<<sizeof(bool)		<<std::endl; 	// 1
	return 0;
}
