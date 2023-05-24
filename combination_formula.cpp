// formula nCr
#include <iostream>

int r_count{0}, f_count{0};


// combination formula using pascal's triangle
int recursive_C(int n, int r) {
    r_count++;

    if (r==0 || n == r) {              // These are the extremes of pascal's triangle
        return 1;                      // and as such are always 1
    } else {
        return recursive_C(n-1,r-1) + recursive_C(n-1, r);
    }
}

// recursive factorial formula
int fact(int n){
    f_count++;
    if (n==0) return 1;
    return fact(n-1)*n;
}

// combination formula using factorial function
int nCr(int n, int r){

    int num, den;       // numerator and denominator

    num = fact(n);
    den = fact(r)*fact(n-r);        // formula : nCr = n!/r!(n-r)!

    return num/den;
}

int main() {

    

    std::cout << recursive_C(4,2) << " : " << r_count << std::endl;
    std::cout << nCr(4,2) << " : " << f_count << std::endl;
    r_count = 0;
    f_count = 0;
    std::cout << recursive_C(3,1) << " : " << r_count << std::endl;
    std::cout << nCr(3,1) << " : " << f_count << std::endl;
}