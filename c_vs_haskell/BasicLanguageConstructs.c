// BasicLanguageConstructs.c
//
// CECS 342
// C vs Haskell
//
// To contrast C and Haskell see: BasicLanguageConstructs.hs


#include "BasicLanguageConstructs.h"
#include <stdio.h>


// Variables
int seven = 7;


// Functions
int twice(int n) {
    return 2 * n;
}

int average(int a, int b) {
    ++seven; // Unexpected side effect
    return (a+b)/2;
}


// Conditionals
int signum0(int n) {
    if (n < 0) return -1;
    if (n > 0) return 1;
    return 0;
}

int signum1(int n) {
    if (n < 0) {
        return -1;
    }
    else {
        if (n > 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int signum2(int n) {
    return (n<0) ? -1 : ((n>0) ? 1 : 0);
}


// Loops and recursion
int factorial1(int n) { // loop
    int f = 1;
    
    for (int k = 1; k <= n; ++k) {
        f *= k;
    }
    
    return f;
}


int factorial2(int n) { // Recursion
    if (n == 0) return 1;
    else return n * factorial2(n-1);
}


int fact_acc(int n, int f) { // Recursion with accumulating parameter
    if (n == 0) return f;
    return fact_acc(n-1, n * f);
}


int factorial3(int n) {
    return fact_acc(n, 1);
}


int fact_acc_tail(int n, int f) { // Tail recursion
start:
    
    if (n == 0) return f;
    
    f *= n;
    --n;
    goto start; // return fact_acc_tail(n-1, n * f);
}


int factorial4(int n) {
    return fact_acc_tail(n, 1);
}


// Loop
int fib1(int n) {
    int a = 0;
    int b = 1;
    
    for (int k = 1; k <= n; ++k) {
        // (a, b) <- (b, a+b)
        int h = a;
        a = b;
        b += h;
    }
    
    return a;
}


// Recursion with accumulating parameters
int fib_acc(int n, int a, int b) {
    if (n == 0) return a;
    return fib_acc(n-1, b, a+b);
}

int fib2(int n) {
    return fib_acc(n, 0, 1);
}

// Short-circuit evaluation (compare with Haskell's lazy evaluation)
int or(int a, int b) { return a || b; }
int and(int a, int b) { return a && b; }


// A simple test suite
int testBasicLanguageConstructs() {
    puts("Test Basic Language Constructs\n");
    
    printf("factorial1(5) = %d\n", factorial1(5));
    printf("factorial2(5) = %d\n", factorial2(5));
    printf("factorial3(5) = %d\n", factorial3(5));
    printf("factorial4(5) = %d\n", factorial4(5));
    printf("fib1(7) = %d\n", fib1(7));
    printf("fib2(7) = %d\n", fib1(7));
    
    puts("");
    
    return 0;
}