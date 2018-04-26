// -----------
// Wed, 25 Apr
// -----------

struct A {
    virtual void f (int) {...}
    virtual void g (int) final {...}
    virtual void h (int) = 0;};

/*
defining f in the child is optional

defining g in the child is prohibited

defining h in the child is required
*/

struct A {
    virtual ~A() {} = 0;};

A::~A() {}

/*
consequences of a pure virtual method
    1. children must override
    2. parent becomes abstract, can't instantiate
    3. in C++ can define (optionally)_ in the parent, in Java can not
*/

/*
consequences of a pure virtual destructor
    1. doesn't hold
    2. parent becomes abstract, can't instantiate
    3. doesn't hold
*/

struct B : A {};

int main () {
    A* p = new B; // A() B()
    delete p;     // ~B() ~A()


Shape* p = new Circle(...);
Shape* q = new Triangle(...);

*p = *q; // can't get it to work nicely

delete p;
p = q-clone();

struct Shape {
    virtual Shape* clone () const = 0;};

struct Circle : Shape {
    Circle* clone () const {
        return new Circle(*this);}};

Circle* p = new Circle(...);
Circle* q = p->clone();

/*
virtual methods can have COVARIANT return types
*/
