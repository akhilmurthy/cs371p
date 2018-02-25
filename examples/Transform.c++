// -------------
// Transform.c++
// -------------

// http://www.cplusplus.com/reference/algorithm/transform/

#include <algorithm>  // transform, equal
#include <cassert>    // assert
#include <functional> // negate
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

using namespace std;

void test1 () {
    const int  a[]  = {2, 3, 4};
    int        b[5] = {};
    const int* p    = transform(a, a + 3, b + 1, negate<int>());
    assert(p == b + 4);
    assert(equal(b, b + 5, begin({0, -2, -3, -4, 0})));}

void test2 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, negate<int>());
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, -2, -3, -4, 0})));}

int main () {
    cout << "Transform.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
