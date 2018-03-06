// -----------
// Mon,  5 Mar
// -----------

/*
Java and C++ have a free store or a heap
*/

int* a = new int[100]; // an array on the heap
...
delete [] a;

int a[5]; // an array on the stack

template <typename T, int N>
class my_allocator {
    private:
        char _a[N]; // divide blocks: free and some busy

    public:
        T* allocate (int) {
            ...}

int main () {
    my_allocator<int,    200> x; // under the hood: an array of 200 bytes
    my_allocator<double, 100> y; // [92...92]

    double* a = y.allocate(5); // a request for space for 5 doubles, 8 * 5 bytes
                               // [-40...-4044...44]
    double* b = y.allocate(3); // a request for space for 5 doubles, 8 * 3 bytes
                               // [-40-40-24...-2412...12]
                               //  48    32

    ...
    double* c = y.allocate(2); // 16

    y.deallocate(a);
    y.deallocate(b);
