#include <stdio.h>
#include <iostream>

void fun(int n) {
    if (n>0) {
        //printf("%d", n);    // c language
        
        // this is "ascending" order:
        /* std::cout << n;
        fun(n-1); */ 

        // this is "descending" order:
        fun(n-1);
        std::cout << n;
    }
}

int main() {
    int x=3;

    fun(x);

    return 0;
}