// -----------
// Wed, 11 Apr
// -----------

/*
three cases of methods in an inheritance
    1. only defined in the parent: move()
    2. only defined in the child:  radius()
    3. defined in both:            area()
*/

struct A {};

A ()
~A ()
A (const A&)
A& operator = (const A&)

class Shape {
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        ...}
    private:
        int _x;
        int _y;
    public:
        Shape (int x, int y) :
            _x (x),
            _y (y)
            {}

        Shape& operator = (const Shape&) = default;

class Circle : public Shape {
    friend bool operator == (const Circle& lhs, const Circle& rhs) {
        return (static_cast<Shape>(lhs) == rhs) && (lhs._r == rhs._r);}
    private:
        int _r;
    public:
        Circle (int x, int y, int r) :
            Shape(x, y),
            _r (r)
            {}

Shape* p = new Circle(...);
assert (*p.area()   == ???); // not ok
assert ((*p).area() == ???);
assert (p->area()   == );

/*
C++ exhibits static binding by default
static binding
    bind the method at compile time

Java exhibits dynamic binding by default
dynamic binding
    bind the method at runtime
*/

class Circle : public Shape {
    friend ostream& operator << (ostream& out, const Circle& val) {
        ...}
    friend istream& operator >> (istream& in, Circle& val) {
        ...}
    private:
        ...
    public:


Circle x(...);
Circle y(...);

assert(x == y);
assert(x.operator==(y));
assert(operator==(x, y));

cout << x << y;
assert(cout... // not ok
assert(operator<<(cout, x));

cin >> x >> y;
