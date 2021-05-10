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

// LINEAR RECURSION
// one recursive call

// tail recursion is where recursive call is the last statement in a block
// performs operations only before func call
// recurTail(n-1) + n --> not a tail recursion func
// can be easily converted into loop which has constant space complexity
// output: 3,2,1
void recurTail(int n){
    if (n > 0){
        printf("reacurTail %d", n);
        recurTail(n - 1);
    }
}
// head recursion is where recursive call is the first statement in a block
// performs operations only after func call
// isnt that easy to conver into a loop
// output: 1,2,3
void recurHead(int n){
    if (n > 0){
        recurHead(n - 1);
        printf("reacurHead %d", n);
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

// TREE RECURSION
// more than one recursive call
// proceeds to a next recursive call only after hitting the bottom
// of a current recursive call
// space complexity: O(n), time complexity O(2^n)
// for n = 5 output: 5432112113211211432112113211211
void recurTreeHead(int n){
    if (n > 0){
        printf("%d", n);
        recurTreeHead(n - 1);
        recurTreeHead(n - 1);
    }
}

// INDERECT RECURSION
// multimple functions call each other in a circular fashion
int recurInderectB(int b);
void recurInderectA(int a){
    if (a > 0){
        printf("%d", a);
        recurInderectB(a-1);
    }
}

int recurInderectB(int b){
    if ( b > 1){
        recurInderectA(b/2);
    }
    return  0;
}

// NESTED RECURSION
// outer function waits until inner returns
int recurNested(int a){
    printf("%d ", a);
    if (a > 10){
        return a - 1;
    }
    return recurNested(recurNested(a + 2));
}

// IMPLEMENTATIONS
// sum of natural numbers: 1+2+3+4+5..
// sum() base case: n = 0 --> 0
// sum(): ( n - 1 ) + n
// too costly for real world scenarios
// return n * ( n + 1 ) / 2 --> constant time
int sumOfNaturalNumbers(int a){
    if (a > 0){
        return sumOfNaturalNumbers(a - 1) + a;
    }
    return 0;
}

// Factorial
int recurFactorial(int a){
    if (a == 0){
        return 1;
    }
    return recurFactorial(a - 1) * a;
}

int iterFactorial(int a){
    if (a <= 1) {
        return 1;
    }
    int n = 1;
    for (int i = 1; i <= a; i++){
       n = n * i;
    }
    return n;
}

int main(int argc, const char * argv[]) {
    int testVal = 5;
    //recurHead(testVal);
    //recurTail(testVal);
    //recurTreeHead(testVal);
    //recurInderectA(testVal);

    int stat1 = recurStatic(testVal);
    // NB! static stays 5 after the last recerStatic call
    int stat2 = recurStatic(testVal);
    
    int stack1 = recurStack(testVal);
    //int nested = recurNested(testVal);

    int sumNatural = sumOfNaturalNumbers(testVal);
    int rfac = recurFactorial(testVal);
    int ifac = iterFactorial(testVal);
    
    printf("recurStatic result 1: %d\n", stat1);
    printf("recurStatic result 2: %d\n", stat2);
    printf("recurStack result 1: %d\n", stack1);
    //printf("recurNested result 1: %d\n", nested);
    printf("sumOfNaturalNumbers result 1: %d\n", sumNatural);
    printf("recurFactorial result 1: %d\n", rfac);
    printf("iterFactorial result 1: %d\n", ifac);

    return 0;
}
