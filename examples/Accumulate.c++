// --------------
// Accumulate.c++
// --------------

// http://www.cplusplus.com/reference/algorithm/accumulate/

#include <cassert>    // assert
#include <functional> // multiples, plus
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <list>       // list

using namespace std;

void test1 () {
    const list<int>          x = {2, 3, 4};
    assert(accumulate(begin(x), end(x), 0, plus<int>()) == 9);}

void test2 () {
    const list<int>          x = {2, 3, 4};
    assert(accumulate(begin(x), end(x), 1, multiplies<int>()) == 24);}

int main () {
    cout << "Accumulate.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
