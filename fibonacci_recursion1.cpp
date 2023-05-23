#include <iostream>

int fib_count {0};
int i_count {0};
int m_count {0};

// excesive recursion
int fib(int n) {
    fib_count++;
    if (n <= 1)
        return n;
    return fib(n-2) + fib(n-1);
}

// recursion with memorization
int array[20];      // initialize array size 20
int m_fib(int n) {
    m_count++;
    if (n <= 1) {
        array[n] = n;
        return n;
    } else {
        if (array[n-2] == -1) {
            array[n-2] = m_fib(n-2);
        }
        if (array[n-1] == -1) {
            array [n-1] = m_fib(n-1);
        }
        return array[n-2] + array[n-1];
    }
}

// iterative
int i_fib(int n) {

    int t0{0}, t1{1}, s{0}, i;

    if (n <= 1) return n;

    for (i = 2; i <= n; i++) {
        i_count++;

        s=t0+t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}



int main() {

    std::cout << fib(10) << " : " << fib_count << std::endl; 
    std::cout << i_fib(10) << " : " << i_count << std::endl;
    for (int i = 0; i <= 20; i++) {      // initialize array content to -1 (since 0 is a fibonacci term)
        array[i] = -1;
    }        
    std::cout << m_fib(10) << " : " << m_count << std::endl; // compare 11 calls vs 177 on excesive recursion
    return 0;
}