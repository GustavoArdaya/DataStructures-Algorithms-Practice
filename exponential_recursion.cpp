#include <iostream>

int count_r {0}, count_s {0}, count_t {0};

int pow(int m, int n) { // m is number to be elevated to nth power
    count_r++;
    if (n == 0)
        return 1;
    return pow(m, n-1) * m;
}

int double_pow(int m, int n) { // this takes half (plus 1 if odd) times compared to previous one
    count_s++;
    if (n==0)
        return 1;
    if (n%2==0)
        return double_pow(m*m, n/2);
    else // number is not even
        return m * double_pow(m*m, (n-1)/2);

}

// iterative solution:
int iPow(int m, int n) {
    int prod {m};
    if (m == 0) return 0;
    if (n == 0) return 1;
    for (int i = 1; i < n; i++) {
        count_t++;
        prod *= m; 
    }
    return prod;
}

int main () {

    int r, s, t;
    
    r = pow(2,9);
    s = double_pow(2,9);
    t = iPow(2,9);

    std::cout << r << " : " << count_r << std::endl;
    std::cout << s << " : " << count_s << std::endl;
    std::cout << t << " : " << count_t << std::endl;

    return 0;
}