// -----------
// Wed, 21 Feb
// -----------

int i = 2;
// different
int i;
i = 2;

T x = y();

int i = 2;
++++i;

template <typename T>
class RangeIterator {
    private:
        T _v;

    public:
//      RangeIterator (T v) { // default constructor
//          _v = v;}           // copy    assignment

        RangeIterator (T v) : // copy constructor
            _v (v)
            {}

        ... operator * () const {
            ...}

        ... operator ++ () { // pre-increment
            ...}

        ... operator ++ (int) { // post-increment
            ...}

        bool operator == (RangeIterator???) {
            ...}

        bool operator != (RangeIterator???) {
            ...}

int main () {
    RangeIterator<int> x = 2;
    RangeIterator<int> y = 2;

    *x;     -> x.operator*();
    x == y; -> x.operator==(y);
    ++x;    -> x.operator++();
    x++;    -> x.operator++(0);















