// ---------
// Range.c++
// ---------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

void test1 () {
    const Range<int> x(2, 2);
    const Range<int>::iterator b = begin(x);
    const Range<int>::iterator e = end(x);
    assert(b == e);}

void test2 () {
    Range<int> x(2, 3);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    assert(b != e);
    assert(2 == *b);
    Range<int>::iterator& y = ++b;
    assert(&y == &b);
    assert(b == e);}

void test3 () {
    Range<int> x(2, 4);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    assert(b != e);
    assert(2 == *b);
    ++b;
    assert(b != e);
    assert(3 == *b);
    b++;
    assert(b == e);}

void test4 () {
    Range<int> x(2, 5);
    assert(my_equal(begin(x), end(x), begin({2, 3, 4})));}

void test5 () {
    Range<int> x(2, 5);
    int s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);}

int main () {
    cout << "Range.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    cout << "Done." << endl;
    return 0;}
