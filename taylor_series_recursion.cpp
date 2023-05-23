#include <iostream>


// quadratic 

double e_quadratic(int x, int n) {
    static double p{1}, f{1};
    double r{0};
    if (n==0)
        return 1;
    else {
        r = e_quadratic(x,n-1);
        p = p * x;      // maneja exponencial
        f = f * n;      // maneja factorial
        return r + p / f;
    }
}

// horner rule - linear

double e_horner(int x, int n) {
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return e_horner(x, n-1);
}


double e_iteration(int x, int n) {
    
    double s {1};
    double num {1};
    double den {1};
    for (int i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main () {

    std::cout << e_quadratic(3,10) << std::endl; // a mayor n, mayor precision.
    std::cout << e_horner(3,10) << std::endl;
    std::cout << e_iteration(3,10) << std::endl;
    return 0;
}