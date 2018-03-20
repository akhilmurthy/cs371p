// -----------
// Mon, 19 Mar
// -----------

T* a = new T[s];

struct A {
    int _v;

    explicit A (int v) {
        _v = v;}};

void f (A y) {
    ...}

int main () (
    A x = 2; // not ok
    A x(2);
    f(x);
    f(A(3));
    f(4);    // not ok

class A {
    public
        friend bool operator == (const A& rhs) const {
            return _v == rhs._v;}

    private:
        int _v;

    public:
        A (int v) {
            _v = v;}};

void f (A y) {
    ...}

int main () (
    A x = 2;
    f(x);
    f(A(3));
    f(4);

    A y = 2;
    assert(x == y); -> assert(x.operator==(y)) -> assert(operator==(x, y)

    assert(x == 2); -> assert(x.operator==(2)) -> assert(operator==(x, 2)
    assert(2 == x); -> assert(2.               -> assert(operator==(2, x)

/*
properties of friend in C++

I declare you to be a friend

what can I be?
    a class

what can you be?
    a function
    a method
    a class

what does it mean to be a friend?
    access to all data

friendship is uni-directional (like Twitter, not Facebook)
friendship is not transitive
*/
