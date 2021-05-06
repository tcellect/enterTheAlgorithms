//
//  main.cpp
//  mySweetCPP
//
//  Created by Deniss Orlov on 25.04.2021.
//

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Book {
    public:
        string title;
        string author;
    
        Book(string title, string author){
            this->title = title;
            this->author = author;
        }

        void readBook () {
            cout << "reading " + this->title + "\n" + "by " + this->author << endl;
        }
};


struct Rectangle {
    int length;
    int width;
};

// called by referrence function will be included into main function in the machine code!!
// that's why it's possible to reference the varriables of it's frame on excecution time
// thus don't pass by reference heavy functions. Those will clutter main
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// this will actually access addresses of variables outside this function frame
void swapPointer(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

// each function has it's own frame in memory on excecution time. Variable of one frame
// can't be accessed directly from another frame. Only with pointers.
// that's why each function might have the same name variables as another one
// passing params by value will create copies of these parameters. Thus operations on these copies
// do not affect original params
int add(int a, int b){
    int s = a + b;
    return s;
}

// arrays can be passes only with pointers
// arr func doesn't know anything about the size of passed array
// that's why I have to pass it. *arr is also legit but it's generic, [] tells that it must be an array
void arr(int arr[], int size){
    // do stuff
}

void arr2(int *arr){
    // sizeof arr gives the size of pointer
    for (int i = 0; i < sizeof(arr); i++){
        printf("arr2 thing %d \n", arr[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    
    // Struct section
    struct Rectangle r1 = {10, 20};
    cout << r1.length << r1.width << endl;
    
    // Class section
    Book book{"petrushka", "unknown"};
    //book.title = "Twelve chairs";
    //book.author = "Ilf and Petrov";
    book.readBook();
    
    
    // Pointers section
    string i = "I'm a working pointer";
    string *pointer1 = &i;
    int A[6] = {1,2,3,4,5,6};
    
    // A is a pointer inself
    int *pointer2 = A;
    
    // an alternative declaration
    //int *pointer2 = &A[0];
    
    cout << *pointer1 << endl;
    // prints 3d element in an array
    cout << pointer2[2] << endl;
    
    // int a << value type
    // int *a << pointer type
    // int &a << reference type !! it's not a pointer. More like an alias for a
    
    int a = 10;
    // must be initialized on declaration
    int &b = a;
    
    int c = 30;
    
    // this actually will change value of a, since b is just referencing its value
    b = c;
    
    //
    cout << b << endl;
    
    Rectangle *pointer3 = &r1;
    
    // C style syntax
    cout << "print object using pointers: " << ((*pointer3).length) << endl;
    // CPP style syntax
    cout << "print object using pointers: " << pointer3->width << endl;
    
    // allocate heap memory for an object
    // new Rectangle, does the same thing in cpp as the line below in c
    Rectangle *p = (Rectangle*)malloc(sizeof(Rectangle));
    
    p->length = 10;
    
    cout << p->length << " located on heap" << endl;

    int testArr[] = {1,2,3,4,5,1,2,2,2,2,2,2};
    arr2(testArr);
    return 0;
}
