// -----------
// Wed, 21 Mar
// -----------

x == 2
x.operator==(2)

2 == x
2.

void f (string y) {
    ...}

void g (vector<int> y) {
    ...}

int main () {
    string x = "abc";
    f(x);
    f("abc");

    vector<int> x(10000);
    vector<int> x = 10000; // not ok
    g(x);
    g(10000);

template <typename T>
class vector {
    private:
        T*  _a;
        int _s;

    public:
        vector () {
            _a = nullptr;
            _s = 0;}


        vector (int s) {
            ???}

        vector (initializer_list<T> a) {
            ???}

        T& operator [] (int i) {
            ???}

        const T& operator [] (int i) const {
            ???}

        int size () const {
            return _s;}

        T* begin () {
            ???}

        const T* begin () const {
            ???}

        T* end () {
            ???}

        const T* end () const {
            ???}
