// -----------
// Wed, 28 Mar
// -----------

template <typename T>
class vector {
    private:
        T* _b = nullptr;
        T* _e = nullptr;
    public:
        vector (const vector& rhs) {
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(begin(rhs), end(rhs), _b);}

        vector& operator = (vector rhs) {
            swap(_b, rhs._b);
            swap(_e, rhs._e);
        /*
            if (this  == rhs)  // not ok
            if (*this == rhs)  // compiles, but still not what we want
            if (this  == &rhs)
                return *this;
            delete [] _b;
            _b = new T[rhs.size()];
            _e = _b + rhs.size();
            copy(begin(rhs), end(rhs), _b);
        */
            return *this;}

        ~vector () {
            delete [] _a;}

int main () {
    vector<int> x(10, 2);
    vector<int> y(20, 3);
    x = y;
