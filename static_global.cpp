#include <iostream>

//int x = 0;

int fun(int n) {

    static int x=0;             // static variables are stored in code memory and not copied in stack
                                // same can be achieved by declaring a global variable outside function
    if (n>0) {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main() {
    
    int r;
    r=fun(5);
    std::cout << r << std::endl;
    r=fun(5);
    std::cout << r << std::endl;            // will display 50, as "x" builds from 5 and not 0 the second time.
    return 0;
}