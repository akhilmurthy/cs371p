// -----------------
// RangeIterator.c++
// -----------------

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
    const RangeIterator<int> b = 2;
    assert(*b == 2);}

void test2 () {
    const RangeIterator<int> b = 2;
    const RangeIterator<int> e = 2;
    assert(b == e);}

void test3 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 3;
    assert(b  != e);
    assert(*b == 2);
    RangeIterator<int>& p = ++b;
    assert(&p == &b);
    assert(b  == e);}

void test4 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 4;
    assert(b  != e);
    assert(*b == 2);
    ++b;
    assert(b  != e);
    assert(*b == 3);
    RangeIterator<int> p = b++;
    assert(&p != &b);
    assert(b  == e);}

void test5 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 5;
    assert(my_equal(b, e, begin({2, 3, 4})));}

int main () {
    cout << "RangeIterator.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    cout << "Done." << endl;
    return 0;}
