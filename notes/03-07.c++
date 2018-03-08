// -----------
// Wed,  7 Mar
// -----------

template <typename T, size_t N>
class my_allocator {
    ...};

int main () {
    my_allocator<double, 100> x;
    cout << x[0];                // -> cout << x.operator[](0), 92
    x[0] = ...;

    const my_allocator<double, 100> y;
    cout << x[0];                      // -> cout << x.operator[](0), 92
    x[0] = ...;                        // not ok

struct A {};

// what I get for free

A()
A(A)
~A()
=(A)
