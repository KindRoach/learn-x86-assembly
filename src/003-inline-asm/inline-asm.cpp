#include <iostream>

int add_three(int a, int b, int c) {
    int result;
    asm volatile (
        "movl %[a], %[res];" // res = a
        "addl %[b], %[res];" // res += b
        "addl %[c], %[res];" // res += c
        : [res] "=r" (result) // output: result = res
        : [a] "r" (a), [b] "r" (b), [c] "r" (c) // inputs
    );
    return result;
}

int main() {
    int x = 5, y = 10, z = 20;
    int res = add_three(x, y, z);
    std::cout << x << " + " << y << " + " << z << " = " << res << std::endl;
    return 0;
}
