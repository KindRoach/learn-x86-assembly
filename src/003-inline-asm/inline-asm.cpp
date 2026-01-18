#include <iostream>

int add_three_placeholder_reg(int a, int b, int c)
{
    int result;
    asm volatile(
        "movl %1, %0;"           // result = a
        "addl %2, %0;"           // result += b
        "addl %3, %0;"           // result += c
        : "=r"(result)           // output: result in any register
        : "r"(a), "r"(b), "r"(c) // input: a, b, c in registers
    );
    return result;
}

int add_three_symbolic_named_reg(int a, int b, int c)
{
    int result;
    asm volatile(
        "movl %[a], %[res];"                 // res = a
        "addl %[b], %[res];"                 // res += b
        "addl %[c], %[res];"                 // res += c
        : [res] "=r"(result)                 // output: result = res
        : [a] "r"(a), [b] "r"(b), [c] "r"(c) // inputs
    );
    return result;
}

int main()
{
    int x = 5, y = 10, z = 20;
    std::cout << "add_three_placeholder_reg(" << x << ", " << y << ", " << z << ") = " << add_three_placeholder_reg(x, y, z) << std::endl;
    std::cout << "add_three_symbolic_named_reg(" << x << ", " << y << ", " << z << ") = " << add_three_symbolic_named_reg(x, y, z) << std::endl;
    return 0;
}
