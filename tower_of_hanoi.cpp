#include <iostream>

int count {0};
int movement {0};

void TOH(int n, int A, int B, int C) {
    count++;
    if (n>0) {
        TOH(n-1, A, C, B);
        movement++;
        std::cout << movement << ". Move disc " << n << " from column " << A << " to column " << C << std::endl;
        TOH(n-1, B, A, C);
    }
}

int main () {


    TOH(4,1,2,3);
    std::cout << "recursion count : " << count << std::endl;
    return 0;
}