#include <iostream>


// Using Recursion
int sum(int n) {

    if (n == 0) 
        return 0;
    return sum(n-1) + n;
}

// using for loop - iterative solution
int Isum(int n) {

    int s = 0;      // to store sum
    int i;          // for counter
    for (i=1; i <= n; i++)
        s=s+i;
    return s;

} 

int main() {

    int r, s;

    r = sum(5);
    s = Isum(5);
    std::cout << r << std::endl;
    std::cout << s << std::endl;
    
    return 0;
}