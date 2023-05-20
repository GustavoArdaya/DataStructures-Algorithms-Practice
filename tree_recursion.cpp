#include <iostream>

int count {0};

void fun(int n) {
    count++;
    if (n>0){
        std::cout << n << " ";
        fun(n-1);   // 1 call (x) with n = 3 : 1^3 + 1^2 + 1^1 + 1^0 = 4
        fun(n-1);   // 2 calls (x) with n = 3 : 2^3 + 2^2 + 2^1 + 2^0 = 15
        fun(n-1);   // 3 calls (x) with n = 3 : 3^3 + 3^2 + 3^1 + 3^0 = 40
    }
}

int main() {
    fun(3);
    std::cout << std::endl;
    std::cout << "function call count: " << count;
    return 0;
}