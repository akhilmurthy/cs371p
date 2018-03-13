// -----------
// Vector1.c++
// -----------

// http://en.cppreference.com/w/cpp/container/vector

#include <algorithm>        // equal
#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

using namespace std;

void test1 () {
    const vector<int> x;
    assert(x.size() == 0);}

void test2 () {
    const vector<int> x(3);
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({0, 0, 0})));}

void test3 () {
    const vector<int> x(3, 2);
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({2, 2, 2})));}

void test4 () {
    const initializer_list<int> x = {2, 3, 4};
    assert(x.size() == 3);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));
    const vector<int> y(x);
    assert(y.size() == 3);
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

void test5 () {
    vector<int> x = {2, 3, 4};
    assert(x[1] == 3);
    x[1] = 5;
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void test6 () {
    const vector<int> x = {2, 3, 4};
    assert(x[1] == 3);
//  x[1] = 5;                                           // error: cannot assign to return value because function 'operator[]' returns a const value
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

int main () {
    cout << "Vector1.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "Done." << endl;
    return 0;}
