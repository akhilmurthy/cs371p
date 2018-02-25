// -------------
// Functions.c++
// -------------

#include <algorithm>  // transform
#include <cassert>    // assert
#include <cmath>      // pow
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

using namespace std;

template <typename T>
T square_1 (const T& x) {
    return pow(x, 2);}

void test1 () {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    const function<int (int)> f = square_1<int>;
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

template <typename T>
struct square_2  {
    T operator () (const T& x) const {
        return pow(x, 2);}};

void test2 () {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    const function<int (int)> f = square_2<int>();
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

void test3 () {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    const function<int (int)> f = [] (int x) -> int {return pow(x, 2);};
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

void test4 () {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    const int                 n = 2;
    const function<int (int)> f = [n] (int x) -> int {return pow(x, n);};
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

void test5 () {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    int                       n = 1;
    const function<int (int)> f = [n] (int x) -> int {return pow(x, n);};
    ++n;
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 2, 3, 4, 0})));}

void test6 () {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    int                       n = 1;
    const function<int (int)> f = [&n] (int x) -> int {return pow(x, n);};
    ++n;
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

int main () {
    cout << "Functions.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "Done." << endl;
    return 0;}
