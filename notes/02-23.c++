// -----------
// Fri, 23 Feb
// -----------

template <typename T>
struct multiplies {
    T operator () (T x, T y) {
        return x * y;}};

int main () {
    int i = 2;
    int j = 3;
    // auto f = multiplies<int>();
    multiplies<int> f;
    int j = f(2, 3);               # 6
    int j = f.operator()(2, 3);    # 6

    RangeIterator<int> x(2);
    *x   -> x.operator*()
    ++x  -> x.operator++()
    x++  -> x.operator++(0)
    x==y -> x.operator==(y)

template <typename II, typename T, typename BF>
T accumulate (II b, II e, T v, BF f) {
    while (b != e) {
        v = f(v, *b);
        ++b;}
    return v;}

template <typename T>
class Range {
    public:
        class iterator

    private:
        T _b;
        T _e;

    public:
        Range (T b, T e) :
            _b (b),
            _e (e)
            {}

        iterator begin () {
            return iterator(_b);}

        iterator end () {
            return iterator(_e);}};
