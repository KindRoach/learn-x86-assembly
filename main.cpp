#include <iostream>
#include "lib.hpp"

int main()
{
    auto x = add_int_asm(1, 2);
    std::cout << x << std::endl;
}
