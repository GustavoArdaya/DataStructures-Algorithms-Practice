#include <iostream>

class Array {

private:

    int *A;         // initializing as pointer allows dynamic allocation of size
    int size;
    int length;

    void swap(int *x, int *y);

public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int size) {
        this->size = size;
        length = 0;
        A = new int[size];
    }
    ~Array(){
        delete []A;
    }

    int getSize() {
        return size;
    }

    int getLength() {
        return length;
    }    

    void display();
    void append(int x);
    void insert(int index, int x);
    int del(int index);
    
    int linearSearch(int key);
    int enhancedLinearSearch (int key);
    int enhancedMovetoHead (int key);

    int binarySearch(int key);

    int get(int index);
    void set(int index, int x);
    int max();
    int min();
    int sum();
    double avg();

    void reverse();
    void reverse2();
    void left_shift();
    void right_shift();
    void left_rotate();
    void right_rotate();

    void insertSort(int x);
    bool isSorted();
    void rearrange();

    Array* merge(Array arr2);
    Array* set_union(Array arr2);
    Array* set_intersection(Array arr2);
    Array* set_difference(Array arr2);
};

void Array::swap(int *x, int *y) { // this function, since it returns void, should recieve addresses (pointers)
    
    int temp;   //   an integer variable,
    temp = *x;  //   which is assigned the derreferenced value of x
    *x = *y;    //   whose value (derref) is then assigned the derref value of y.
    *y = temp;  //   Finally the address of y's value is asigned to the int stored in temp. No return, but values in memory have been modified 

}

void Array::display() {
    std::cout << "\nElements are" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void Array::append(int x) {
    if (length < size)
        A[length++] = x;
}

void Array::insert(int index, int x) {
    if (index >= 0 && index <= length) {

        for (int i = length; i > index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
}

int Array::del(int index) {

    int x {0};
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }

    return 0;
}

int Array::linearSearch(int key) {

    for (int i = 0; i < length; i++) {
        if (key == A[i])
            return i;
    }
    return -1;
}

int Array::enhancedLinearSearch (int key) { // receives a reference, since it will modify array

    for (int i = 0; i < length; i++) {
        if (key==A[i] && i > 0) {
            Array::swap (&A[i], &A[i-1]);
            return i;
        } else if (key==A[i] && i == 0)
            return i;            
    }
    return -1;
}

int Array::binarySearch(int key) {

    int l {0}, h {length-1}, mid;
    
    while (l <= h) {

        mid = ( l + h ) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1; 
    }

    return -1;
}

int Array::enhancedMovetoHead (int key) { // receives a reference, since it will modify array

    for (int i = 0; i < length; i++) {
        if (key==A[i] && i > 0) {
            swap (&A[i], &A[0]);
            return i;
        } else if (key==A[i] && i == 0)
            return i;            
    }
    return -1;
}

int Array::get(int index) {
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array::set(int index, int x) {
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::max() {
    int max = A[0];
    
    for (int i = 1; i < length; i++) {
        if (A[i] > max) max = A[i];
    }
    return max;
}

int Array::min() {
    int min = A[0];
    
    for (int i = 1; i < length; i++) {
        if (A[i] < min) min = A[i];
    }
    return min;
}

int Array::sum() {
    int sum {0};
    for (int i = 0; i < length; i++) {
        sum += A[i];
    }
    return sum;
}

double Array::avg() {
    return (double) sum()/length;
}

void Array::reverse() {

    for (int i = 0, j = length-1; i < j; i++, j--) {
        int temp;
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

void Array::reverse2() {           // uses reference

    int *tempArr = new int[size];

    for (int i = length-1, j = 0; i >= 0; i--, j++) {
        tempArr[j] = A[i];
    }
    for (int i = 0; i < length; i++) {
        A[i] = tempArr[i];
    }    
}

void Array::left_shift() {      // sets rightmost element to 0

    for (int i = 0; i < length; i++) {
        A[i] = A[i+1];
    }
    A[length-1] = 0;
}

void Array::right_shift() {     // sets leftmost element to 0

    for (int i = length - 1; i > 0; i--) {
        A[i] = A[i-1];
    }
    A[0] = 0;
}

void Array::left_rotate() {     // "moves" leftmost element to end

    int temp = A[0];
    for (int i = 0; i < length; i++) {
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}

void Array::right_rotate() {    // "moves rightmost elemento to start"

    int temp = A[length-1];
    for (int i = length - 1; i > 0; i--) {
        A[i] = A[i-1];
    }
    A[0] = temp;
}

void Array::insertSort(int x) {

    if (length == size)
        return;
    int i = length-1;

    while (A[i] > x) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

bool Array::isSorted() {

    for (int i = 0; i < length - 1; i++) {
        if (A[i] > A[i+1]) {
            return false;
        }
    }
    return true;
}

void Array::rearrange() {
    int i {0}, j {length-1};

    while (i < j) {

        while(A[i] < 0) i++;
        while(A[i] >= 0) j--;

        if (i < j) {

            Array::swap(&A[i], &A[j]);
        }
    }
}

Array* Array::merge(Array arr2) {
    int i, j, k;
    i=j=k=0;

    Array *arr3 = new Array(length+arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i < length ; i++) 
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = length + arr2.length;

    return arr3;
}

Array* Array::set_union(Array arr2) {
    int i{0}, j{0}, k{0};

    Array *arr3 = new Array(length+arr2.length);

    while (i < length && j < arr2.length) {

        if (A[i] < arr2.A[j]) {
            arr3->A[k++] = A[i++];   // Fuerte! se usa y luego Post-Increment! 
        } else if (arr2.A[j] < A[i]){
            arr3->A[k++] = arr2.A[j++];
        } else {    // meaning they're equal
            arr3->A[k++] = A[i++];    // copies any of the elements. In this case first
            j++;                            // dont forget to increment j!
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = k;

    return arr3;
}

Array* Array::set_intersection(struct Array arr2) {
    int i{0}, j{0}, k{0};
    
    Array *arr3 = new Array(length+arr2.length);


    while (i < length && j < arr2.length) {

        if (A[i] < arr2.A[j]) {
            i++;   // si son diferentes se mueve indice
        } else if (arr2.A[j] < A[i]){
            j++;
        } else {    // meaning they're equal
            arr3->A[k++] = A[i++];    // copies any of the elements. In this case first
            j++;                            // dont forget to increment j!
        }
    }
    
    arr3->length = k;

    return arr3;
}

Array* Array::set_difference(Array arr2) {
    int i{0}, j{0}, k{0};

    Array *arr3 = new Array(length+arr2.length);

    while (i < length && j < arr2.length) {

        if (A[i] < arr2.A[j]) {
            arr3->A[k++] = A[i++];   
        } else if (arr2.A[j] < A[i]){
            j++;            // no nos interesa copiar elemento de segundo array
        } else {    // meaning they're equal
            i++;    // copies any of the elements. In this case first
            j++;                            // dont forget to increment j!
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];

    // no se copia elementos restantes de 2do array
    arr3->length = k;

    return arr3;
}

/*

int main() {

    
    int ch;
    int size;
    int x, index;

    std::cout << "Enter the size of number array: ";
    std::cin >> size;

    Array *arr1 = new Array(size);

    do {
        std::cout << "\n\nMenu\n"
                  <<"1. Insert\n"
                  <<"2. Delete\n"
                  <<"3. Search\n"
                  <<"4. Sum\n"
                  <<"5. Display\n"
                  <<"6.Exit\n";

        std::cout << "enter you choice: ";
        std::cin >> ch;

        switch(ch) {
            case 1: std::cout << "Enter an element and index ";
                std::cin >> x >> index;
                arr1->insert(index,x);
                break;

            case 2: std::cout << "Enter index ";
                std::cin >> index;
                x = arr1->del(index);
                std::cout << "Deleted Element is " << x;
                break;
            case 3: std::cout << "Enter element to search ";
                std::cin >> x;
                index=arr1->linearSearch(x);
                std::cout << "Element is in index " << index;
                break;
            case 4: std::cout << "Sum is " << arr1->sum();
                break;
            case 5:arr1->display();

        }
    }while(ch<6);

    return 0;
} */