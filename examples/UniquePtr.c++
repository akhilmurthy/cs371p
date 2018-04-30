// -------------
// UniquePtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // unique_ptr

using namespace std;

struct A {
    static int c;                 // number of current A instances

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

void test1 () {
    assert(A::c == 0);
    {
//  unique_ptr<A> x = new A;      // unique_ptr's constructor MUST be explicit
    unique_ptr<A> x(new A);
    assert(x.get() != nullptr);
    assert(A::c    == 1);
    }                             // destructor
    assert(A::c == 0);}

void test2 () {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    assert(A::c == 1);
//  unique_ptr<A> y = x;          // unique_ptr's copy constructor MUST be deleted
//  unique_ptr<A> y(x);           // unique_ptr's copy constructor MUST be deleted
    unique_ptr<A> y = move(x);    // move constructor
    assert(x.get() == nullptr);
    assert(y.get() != nullptr);
    assert(A::c    == 1);
    }
    assert(A::c == 0);}

void test3 () {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    unique_ptr<A> y(new A);
    assert(A::c == 2);
//  x = y;                        // unique_ptr's copy assignment MUST be deleted
    x = move(y);                  // move assignment
    assert(x.get() != nullptr);
    assert(y.get() == nullptr);
    assert(A::c    == 1);
    }
    assert(A::c == 0);}

int main () {
    cout << "UniquePtr.c++" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
