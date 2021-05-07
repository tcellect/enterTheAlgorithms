//
//  main.cpp
//  recursion
//
//  Created by Deniss Orlov on 06.05.2021.
//

#include <stdio.h>

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
        T(n) = T( n - 1 ) + 1 = T(n)
 6. recurance relation
*/

// tail recursion is where recursive call is the last statement in a block
// performs operations only before func call
// recurTail(n-1) + n --> not a tail recursion func
// can be easily converted into loop which has constant space complexity
// order: 3,2,1
void recurTail(int n){
    if (n > 0){
        recurTail(n - 1);
    }
}
// head recursion is where recursive call is the first statement in a block
// performs operations only after func call
// isnt that easy to conver into a loop
// order: 1,2,3
void recurHead(int n){
    if (n > 0){
        recurHead(n - 1);
    }
}

// new copy of n is created on each call
int recurStack(int n){
    if (n > 0) {
        // it goes like that assuming n is 5:
        // left is what's returned and right is what a frame stores
        // call 6: 0
        // call 5: 0 + 1
        // call 4: 1 + 2
        // call 3: 3 + 3
        // call 2: 6 + 4
        // call 1: 10 + 5 -- > result is 15
        return recurStack(n - 1) + n;
    }
    return 0;
}

// recursion with static vars.
// global and static vars are outside
// of frames created by recursive func calls
int recurStatic(int n){
    static int st = 0;
    if (n > 0){
        st++;
        // it goes like that assuming n is 5:
        // left is what's returned and right is what the static/global var accumulated
        // call 6: 0
        // call 5: 0 + 5
        // call 4: 5 + 5
        // call 3: 10 + 5
        // call 2: 15 + 5
        // call 1: 20 + 5 -- > result is 25
        return recurStatic(n - 1) + st;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int testVal = 5;
    //recurR(testVal);
    //recurC(testVal);
    
    int stat1 = recurStatic(testVal);
    // NB! static stays 5 after the last recerStatic call
    int stat2 = recurStatic(testVal);
    
    int stack1 = recurStack(testVal);


    printf("recurStatic call 1: %d\n", stat1);
    printf("recurStatic call 2: %d\n", stat2);
    printf("recurStack call 1: %d\n", stack1);


    return 0;
}
