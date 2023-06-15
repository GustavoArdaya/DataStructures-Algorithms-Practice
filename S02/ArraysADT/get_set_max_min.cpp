#include <iostream>

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

int get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int max(struct Array arr) {
    int max = arr.A[0];
    
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) max = arr.A[i];
    }
    return max;
}

int min(struct Array arr) {
    int min = arr.A[0];
    
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) min = arr.A[i];
    }
    return min;
}

int sum(struct Array arr) {
    int sum {0};
    for (int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }
    return sum;
}

float avg(struct Array arr) {
    return (float) sum(arr)/arr.length;
}

int main() {

    struct Array arr = {{2,3,4,5,6}, 10, 5};

    std::cout << "element in index 2: " << get(arr, 2) << std::endl;
    set(&arr, 2, 10);
    std::cout << "set element in index 2 to 10: " << get(arr, 2) << std::endl;
    std::cout << "max element in array: " << max(arr) << std::endl;
    std::cout << "min element in array: " << min(arr) << std::endl;

    std::cout << "sum of elements in array: " << sum(arr) << std::endl;
    std::cout << "average of elements in array: " << avg(arr) << std::endl;

    return 0;
}