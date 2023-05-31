#include <iostream>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array arr) {
    std::cout << "Elements are:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i];
    }
}

int main() {

    struct Array arr;
    int n;
    std::cout << "Enter size of array:";
    std::cin >> arr.size;
    arr.A= (int *)malloc(arr.size*sizeof(int)); // c style heap allocation
    arr.length=0;

    std::cout << "\nEnter number of numbers: ";
    std::cin >> n;

    std::cout << "\nEnter all elements:\n";

    for (int i = 0; i < n; i++) {
        std::cin >> arr.A[i];
    }
    arr.length = n;

    display(arr);

    return 0;
}