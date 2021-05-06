#include <iostream>
#include <algorithm>

void increment(int* x){ // variable address (pointer) parameter
    ++*x;   // increment value at address
}

void takes_array(int* array){    // array parameters decay to pointers of first value, pointer syntax used for clarity
    *array = 10;    // actual value of array changed given pointer parameter
    std::cout << array+1 << '\n';   // sequential int address found using scaling
    *(array+1) = 11;    // pointer arithmetic performed to change sequential value inside array passed
}

void pointers(){
    int x{2};   // variable name x identifier for memory location
    std::cout << &x << '\n';    // & = address-of operator, showing variable memory location
    std::cout << *(&x) << '\n';    // * = indirection operator, showing memory location value

    int* xPtr{&x}; // pointer declaration uses *, pointers only hold address values, type corresponds to variable x
    std::cout << xPtr << '\n';  // memory address of x
    std::cout << *xPtr << '\n'; // value at memory address of x
    *xPtr = 10;
    std::cout << x << '\t' <<  *xPtr << '\n';   // the value at the address of the pointer directly changes the value

    double* ptr{nullptr};  // null pointer, preventing assignment to garbage

    int val{6}; // variable hold 6
    int* valPtr{&val};  // pointer holds address for variable
    increment(valPtr);  // function takes pointer parameter, val = 7
}

void arrayPtr() {
    int array[3]{1, 2, 3};
    std::cout << array << '\n'; // array decays to address of array[0]
    takes_array(array);
    std::cout << array[0] << '\n';    // output value stored at address of array[0]

    const int l{sizeof(array) / sizeof(array[0])};
    for (int i = 0; i < l; ++i) { std::cout << array[i] << '\t'; }
    std::cout << '\n';
}

bool hasA(char ch){
    switch (ch){
        case 'A':
        case 'a':
            return true;
        default:
            return false;
    }
}

int* find(int* start, int* end, int val){
    for (int* p{start}; p != end; ++p){
        if (*p == val){
            return p;
        }
    }
    return end;
}

void charPtr(){
    char name[]{"Sebastian"};
    auto numVowels{ std::count_if(std::begin(name), std::end(name), hasA) };
    // std::count_if counts items that satisfy the condition
    std::cout << name << " has " << numVowels << " a's\n";
}

void searchArray(){
    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};
    int* found = find(std::begin(arr), std::end(arr), 20);
    std::cout << "found "<< *found << " at " << found << '\n';
}

int main(){
    searchArray();
    return 0;
}