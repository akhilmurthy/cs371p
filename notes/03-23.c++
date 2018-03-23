// -----------
// Fri, 23 Mar
// -----------

template <typename T>
class vector {
    private:
        int _s = 0;
        T*  _a = nullptr;

    public:
        vector () = default;

        int size () const {
            return _s;}

        vector (int s) {
            _s = s;
            _a = new T[_s];
            fill(_a, _a + _s, T());}

        T* begin () {
            return _a;}

        const T* begin () const {
            return _a;}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return _a + _s;}

        vector (int s, const T& v) {
            _s = s;
            _a = new T[_s];
            fill(_a, _a + _s, v);}

        vector (initializer_list<T> x) {
            _s = x.size();
            _a = new T[_s];
            copy(begin(x), end(x), _a);}

        T& operator [] (int i) {
            return _a[i];

        const T& operator [] (int i) const {
            return _a[i];

        vector (const vector& rhs) {
            _s = rhs._s;
            _a = rhs._a;}

        ~vector () {
            delete [] _a;}

        vector& operator = (const vector& rhs) {
            _s = rhs._s;
            _a = rhs._a;
            return *this;}

struct A {};

A()
A(const A&)
~A()
=(const A&)

void f (vector<int> z) {
    ...}

int main () {
    vector<int> x(10, 2);
    vector<int> y = x;
    // changes to y become changes to x
    f(x);

    vector<int> t(20, 3);
    x = t;
    x.operator=(t);
