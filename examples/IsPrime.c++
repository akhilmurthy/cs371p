// -----------
// IsPrime.c++
// -----------

// https://en.wikipedia.org/wiki/Primality_test

#include <cassert>  // assert
#include <cmath>    // sqrt
#include <iostream> // cout, endl

using namespace std;

bool is_prime (int n) {
    assert(n > 0);
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i < std::sqrt(n); ++i)
        if ((n % i) == 0)
            return false;
    return true;}

void test1 () {
    assert(!is_prime( 1));}

void test2 () {
    assert(!is_prime( 2));}

void test3 () {
    assert( is_prime( 3));}

void test4 () {
    assert(!is_prime( 4));}

void test5 () {
    assert( is_prime( 5));}

void test6 () {
    assert( is_prime( 7));}

void test7 () {
    assert( is_prime( 9));}

void test8 () {
    assert(!is_prime(27));}

void test9 () {
    assert( is_prime(29));}

int main () {
    cout << "IsPrime.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    cout << "Done." << endl;
    return 0;}
