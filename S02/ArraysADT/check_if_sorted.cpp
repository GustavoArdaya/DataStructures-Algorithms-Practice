#include <iostream>

struct Array{
    int A[10];                              // fixed size array in stack
    int size;
    int length;                             // length is the number of assigned elements in size
};

void swap(int *x, int *y) { 
    
    int temp;   
    temp = *x; 
    *x = *y;    
    *y = temp;  

}
void insertSort(struct Array *arr, int x) {

    if (arr->length==arr->size)
        return;
    int i = arr->length-1;

    while (arr->A[i] > x) {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;

}

bool isSorted(struct Array arr) {

    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i+1]) {
            return false;
        }
    }

    return true;
}

void display(struct Array arr) {
    std::cout << "Elements are:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i] << " ";
    }
}

/*void rearrange(struct Array *arr) {
    int i {0}, j {arr->length-1};

    while (i < j) {

        while(arr->A[i] < 0) i++;
        while(arr->A[i] >= 0) j--;
        if (i < j) {

            int temp;   
            temp = arr->A[i]; 
            arr->A[i] = arr->A[j];    
            arr->A[j] = temp;  
            //swap(&arr->A[i], &arr->A[j]);
        }
    }
} */



int main () {

    struct Array arr = {{2,3,5,10,15}, 10, 5};
    struct Array arr1 = {{1,4,3,6,2}, 10, 5};
    struct Array arr2 = {{1,-4,3,6,-2}, 10, 5};

    display(arr);
    insertSort(&arr, 4);
    std::cout << std::endl;
    display(arr);
    std::cout << std::endl;
    std::cout << isSorted(arr1) << std::endl;    
    // display(arr2);
    //rearrange(&arr2);
    //display(arr2);

    return 0;

}