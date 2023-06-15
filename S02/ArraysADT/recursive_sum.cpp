#include <iostream>

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

int recursive_sum(struct Array array, int n) {
    if (n < 0) return 0;
    else return recursive_sum(array, n-1) + array.A[n];
}

int main () {

    struct Array arr = {{2,3,4,5,6}, 10, 5};

    std::cout << recursive_sum(arr, arr.length - 1);

    return 0;
}