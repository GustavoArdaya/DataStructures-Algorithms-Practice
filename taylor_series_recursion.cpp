#include <iostream>

double e(int x, int n) {
    static double p{1}, f{1};
    double r{0};
    if (n==0)
        return 1;
    else {
        r = e(x,n-1);
        p = p * x;      // maneja exponencial
        f = f * n;      // maneja factorial
        return r + p / f;
    }
}

int main () {

    std::cout << e(3,10) << std::endl; // a mayor n, mayor precision.
    return 0;
}