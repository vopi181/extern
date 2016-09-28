#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main() {
    int test = 123;
    int* iptr = &test;
    auto x = iptr;
    std::cout << *x << std::endl;
    std::cout << &test << std::endl;
    getchar();
    std::cout << *x << std::endl;
    std::cout << &test << std::endl;
    getchar();
    int z = 1;
    while(z == 1) {
    std::cout << *x << std::endl;
    std::cout << &test << std::endl;
    usleep(3000000);
    }
    return 0;

}