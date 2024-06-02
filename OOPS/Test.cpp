#include <iostream>
#include <utility>

int main() {
    auto a =
            #define F(x,y) std::make_pair(x+y, x);
            #include "data.inc"
            #undef F

    auto b =
            #define F(x,y) std::make_pair(x##y, #x);
            #include "data.inc"
            #undef F

    std::cout << "Second: " << a.second + 1 << b.second + 1 << std::endl;
    std::cout << "First: " << a.first + b.first << b.second + 1 << std::endl;
}
