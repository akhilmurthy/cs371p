// -----------
// Wed,  4 Apr
// -----------

vector<T, allocator<T>> x(s, v, allocator<T>());

template <typename T, typename A = std::allocator<T>>
class vector {
    private:
        A  _a;
        T* _b = nullptr;
        T* _e = nullptr;

    public:
        vector (int s, const T& v, A a = A()) :
            _a (a) {            // A(A)
            _b = a.allocate(s);
            _e = _b + s;
            unitialized_fill(a, _b, _e, v);}

        vector (vector&& rhs) :
                _a (move(rhs._a)) {
            swap(_b, rhs._b);
            swap(_e, rhs._e);}

        ~vector () {
            destroy(_a, _b, _e);
            _a.deallocate(_b);}

/*
cost of vector:
    adding to the front:  O(n)
    adding to the middle: O(n)
    adding to the back:   amortized O(1)
    cost of indexing:     O(1)
*/

vector<int> x(10, 2);
cout << x.size();     // 10
cout << x.capacity(); // 10
int* p = &x[5];
cout << *p;           //  2
x.push_back(3);
cout << x.size();     // 11
cout << x.capacity(); // 20
cout << *p;           // <crash>

/*
cost of deque:
    adding to the front:  amortized O(1), cheaper than vector's
    adding to the middle: O(n), more expensive than vector's
    adding to the back:   amortized O(1), cheaper than vector's
    cost of indexing:     O(1), more expensive O(1) than vector's
*/

deque<int> y(30, 2);
cout << y[13];
y.push_back(3);

/*
cost of list:
    adding to the front:  O(1)
    adding to the middle: O(1)
    adding to the back:   O(1)
    cost of indexing:     NA
*/

/*
container adapters
    stack
        vector
    queue
    priority_queue
*/

/*
class relationships
    containment
        reuse implementation
    inheritance
        reuse implementation
        reuse interface
*/

/*
Java's Stack incorrectly inherits from Vector
C++'s  stack correctly   contains vector
*/
