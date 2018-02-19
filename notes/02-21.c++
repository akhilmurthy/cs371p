// -----------
// Wed, 21 Feb
// -----------

template <typename T>
class range_iterator {
    private:
        T _v;

    public:
//      range_iterator (T v) { // default constructor
//          _v = v;}           // copy    assignment

        range_iterator (T v) : // copy constructor
            _v  (v)
            {}

