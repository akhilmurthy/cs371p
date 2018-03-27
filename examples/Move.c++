// --------
// Move.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // move

using namespace std;

template <typename T>
struct A {
    A () {
        cout << "A() ";}

    A (const A&) {                 // copy constructor
        cout << "A(const A&) ";}

    A (A&&) {                      // move constructor
        cout << "A(A&&) ";}

    A& operator = (const A&) {     // copy assignment
        cout << "=(const A&) ";
        return *this;}

    A& operator = (A&&) {          // move assignment
        cout << "=(A&&) ";
        return *this;}

    ~A() {
        cout << "~A() ";}};



template <typename T>
struct B {
    A<T> _x;                       // containment

    B () :
            _x () {
        cout << "B() ";}

    B (const B& rhs) :
            _x (rhs._x) {
        cout << "B(const B&) ";}

    B& operator = (const B& rhs) {
        _x = rhs._x;
        cout << "=(const B&) ";
        return *this;}

    ~B() {
        cout << "~B() ";}};

void test1 () {
    cout << "B. copy: ";
    B<int> x;            // A() B()
    B<int> y = move(x);  // A(const A&) B(const B&);
    }

void test2 () {
    cout << "B. asgn: ";
    B<int> x;            // A() B()
    B<int> y;            // A() B()
    y = move(x);         // =(const A&) =(const B&)
    }



template <typename T>
struct C {
    A<T> _x;                       // containment

    C () :
            _x () {
        cout << "C() ";}

    C (const C& rhs) :
            _x (rhs._x) {
        cout << "C(const C&) ";}

    C (C&& rhs) :
            _x (move(rhs._x)) {
        cout << "C(C&&) ";}

    C& operator = (const C& rhs) {
        _x = rhs._x;
        cout << "=(const C&) ";
        return *this;}

    C& operator = (C&& rhs) {
        _x = move(rhs._x);
        cout << "=(C&&) ";
        return *this;}

    ~C() {
        cout << "~C() ";}};

void test3 () {
    cout << "C. copy: ";
    C<int> x;            // A() C()
    C<int> y = move(x);  // A(A&&) C(C&&)
    }

void test4 () {
    cout << "C. asgn: ";
    C<int> x;            // A() C()
    C<int> y;            // A() C()
    y = move(x);         // =(A&&) =(C&&)
    }

int main () {
    cout << "Move.c++" << endl;
    test1();
    cout << endl;
    test2();
    cout << endl << endl;
    test3();
    cout << endl;
    test4();
    cout << endl;
    cout << "Done." << endl;
    return 0;}

/*
B. copy: A() B() A(const A&) B(const B&) ~B() ~A() ~B() ~A()
B. asgn: A() B() A() B() =(const A&) =(const B&) ~B() ~A() ~B() ~A()

C. copy: A() C() A(A&&) C(C&&) ~C() ~A() ~C() ~A()
C. asgn: A() C() A() C() =(A&&) =(C&&) ~C() ~A() ~C() ~A()
*/
