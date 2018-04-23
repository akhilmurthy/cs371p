// -----------
// Mon, 23 Apr
// -----------

struct A {
    void f (int) {...}};

struct B : A {
    using A::f;
    void f (int i) {
        A::f(i);}
    void f (string) {...}};

int main () {
    B x;
    x.f(2);    // not ok
    x.A::f(2);

struct A {
    virtual void f (int) {...}};

struct B : A {
    void f (int) {...}};

int main () {
    A* p = new B;
    p->f(2);      // B::f

/*
when I override, I better keep the following the same:
    1. return type
    2. name
    3. number of args
    4. type of args
    5. const
*/

struct A {
    virtual void f (long) = 0;}; // pure virtual

void A::f (int) {...}

struct B : A {
    void f (int) {...}};

int main () {
    A* p = new B;
    p->f(2);      // B::f

/*
consequences of a pure virtual method
    1. children must override
    2. parent becomes abstract, can't instantiate
    3. in C++ can define in the parent, in Java can not
*/
