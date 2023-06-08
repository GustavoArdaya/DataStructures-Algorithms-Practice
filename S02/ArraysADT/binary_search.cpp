// LIST MUST BE SORTED!

#include <iostream>
#include <stdlib.h>

int i_count {};
int r_count {};

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

void display(struct Array arr) {            // equivalente a push_back
    std::cout << "Elements are:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;
}

int iterativeBinarySearch(struct Array arr, int key) {

    int l {0}, h {arr.length-1}, mid;
    
    while (l <= h) {
        i_count++;
        mid = ( l + h ) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1; 
    }

    return -1;
}

int recursiveBinarySearch(int a[], int l, int h, int key) {

    int mid;
    r_count++;
    if (l <= h)
    {
        mid = ( l + h ) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return recursiveBinarySearch(a, l, mid-1, key);
        else
            return recursiveBinarySearch(a, mid +1, h, key);
    }
    return -1;
}

int main() {

    struct Array arr = {{1,2,3,4,5,6,7,8,9,10}, 10, 10};

    std::cout << "iterative binary search element '4' is in index " << iterativeBinarySearch(arr,4) << std::endl;
    std::cout << "IBS count: " << i_count << std::endl;
    display(arr);

    std::cout << "recursive binary search element '4' is in index " << recursiveBinarySearch(arr.A, 0, arr.length, 4) << std::endl;
    std::cout << "RBS count: " << r_count << std::endl;
    display(arr);

    return 0;
}