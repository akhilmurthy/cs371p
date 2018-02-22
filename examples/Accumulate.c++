// --------------
// Accumulate.c++
// --------------

// http://www.cplusplus.com/reference/algorithm/accumulate/

#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <list>       // list

using namespace std;

void test1 () {
    const list<int>          x = {2, 3, 4};
    function<int (int, int)> f = [] (int x, int y) -> int {return x + y;};
    assert(accumulate(begin(x), end(x), 0, f) == 9);}

void test2 () {
    const list<int>          x = {2, 3, 4};
    function<int (int, int)> f = [] (int x, int y) -> int {return x * y;};
    assert(accumulate(begin(x), end(x), 1, f) == 24);}

int main () {
    cout << "Accumulate.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
