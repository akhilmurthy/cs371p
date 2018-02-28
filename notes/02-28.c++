// -----------
// Wed, 28 Feb
// -----------

Tiger x = new Tiger(...);
Tiger y = new Mammal(...); // not ok

Mammal z = Tiger(...);

struct A {
    A (int i) {...}};

void f (A y) {...}

int main () {
    A x(2);
    f(x);
    f(A(3));
    f(4);

b == e -> b.operator==(e)

struct JK {...};

int main () {
    JK x;
    cout << *x; // not ok
    JK* p = &x;

struct A {
    int _i;

    A (int i) :
            _i (i)
        {}};

int main () {
    A x(2);
    cout << x._i;  // 2

    A* p = &x;
    cout << p._i;    // not ok
    cout << *p._i;   // not ok
    cout << (*p)._i; // 2
    cout << p->_i;   // 2

T*
const T*
T* const
const T* const
