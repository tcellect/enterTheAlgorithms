//
//  main.cpp
//  recursion
//
//  Created by Deniss Orlov on 06.05.2021.
//

#include <iostream>

/*
 1. what is recursion?
    1. a function that calls itself
    2. has a termination case
    Recursion also has two phases:
        1. ascending
        2. discending
 2. example:
    func(int n){
        if ( n > 0 ):
            print n
            // ascending calls
            func(n-1)
            // discending calls
    }
 3. tracing recursion
 4. stack used in recursion
    for every call a new stack frame with new variables will be created.
    all values will be saved until returned
    therefore space complexity going to be n.
 5. time complexity
 6. recurance relation
 
*/

// will print on return. output: 3,2,1
void recurR(int n){
    if (n > 0){
        recurR(n - 1);
        std::cout << n << " ";
    }
}
// will print on call. output 1,2,3
void recurC(int n){
    if (n > 0){
        std::cout << n << " ";
        recurC(n - 1);
    }
}

int main(int argc, const char * argv[]) {
    recurR(10);
    recurC(10);
    
    return 0;
}
