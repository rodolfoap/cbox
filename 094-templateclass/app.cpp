#include<iostream>

template <typename T, int S>
class Entity{
private:
        T list[S];
	std::string message;
public:
        void bytelen(){ std::cout << sizeof(list) << std::endl; }
	Entity(std::string);
};

template <typename T, int S>
Entity<T, S>::Entity(std::string m): message(m) {
	std::cerr<<message<<std::endl;
}

int main(){
        Entity<int, 9> e("Hello, World!");
        e.bytelen();
        Entity<std::string, 9> f("Hello, World!");
        f.bytelen();
        return 0;
}
