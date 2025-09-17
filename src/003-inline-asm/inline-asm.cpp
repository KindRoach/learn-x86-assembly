#include <iostream>

int add_three(int a, int b, int c) {
    int result;
    asm volatile (
        "addl %[b], %[a];" // a = a + b
        "addl %[c], %[a];" // a = a + c
        : [a] "=&r" (result) // output: result
        : "[a]" (a), [b] "r" (b), [c] "r" (c) // input: a, b, c
    );
    return result;
}

int main() {
    int x = 5, y = 10, z = 20;
    int res = add_three(x, y, z);
    std::cout << x << " + " << y << " + " << z << " = " << res << std::endl;
    return 0;
}
