#include <iostream>

// Recursive Solution
int fact(int n) {

    if (n == 0)
        return 1;
    return fact(n-1)*n;

}

// Iterative Solution

int Ifact(int n) {

    int f {1};      // default case if n = 0;
    int i;          // iteration count
    for (i = 1; i <=n ;i++)
        f = f * i;
    return f;
}

int main() {

    int r, s;

    r = fact(5);
    s = Ifact(5);
    std::cout << r << std::endl;
    std::cout << s << std::endl;
    return 0;
}