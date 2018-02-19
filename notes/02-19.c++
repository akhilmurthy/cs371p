// -----------
// Mon, 19 Feb
// -----------

/*
In C++ and Java, constructors of children are obligated to
call constructors of the parent
*/

/*
ordinary methods exhibit replacement overriding
constructors     exhibit refinement ovderriding
opposite of constructor in C++  is a destructor, refinement
opposite of constructor in Java is finalize,     replacement
everything in Python exhibits replacement
*/

input iterator b
input iterator e
int plus (int x, int y) {
    return x + y;}
accumulate(b, e, 0, plus);

int factorial (int n) {
    range_iterator<int> b = 1;
    range_iterator<int> e = n + 1;
    accumulate(b, e, 1, [] (int x, int y) -> int {return x * y;});

/*
==, !=
++
*
*/

T v = ...;
T x = v;   // copy constructor

T y;       // default constructor
y = v;     // copy    assignment

template <typename T>
class range_iterator {
    private:
        T _v;

    public:
        range_iterator (T v) { // default constructor
            _v = v;}           // copy    assignment

        range_iterator (T v) : // copy constructor
            _v (v)
            {}
