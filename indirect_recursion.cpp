#include <iostream>

void funB(int n);

int count {0};

void funA(int n) {
    count++;
    if (n>0) {
        std::cout << n << " ";
        funB(n-1);
    }
}

void funB(int n) {
    count++;
    if (n>1) {
        std::cout << n << " ";
        funA(n/2);
    }
}

int main () {

    funA(20);
    std::cout << std::endl;
    std::cout << "function call count: " << count;
    return 0;
}