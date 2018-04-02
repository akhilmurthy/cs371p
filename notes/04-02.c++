// -----------
// Mon,  2 Apr
// -----------

T v(...);
T* a = new T[s];   // O(1) or O(n), T()
fill(a, a + s, v); // O(n)          =(T)

// change that to using an allocator

allocator<T> x;
T* a = x.allocate(s); // O(1), <nothing>
for (int i = 0; i != s; ++i)
    x.construct(a + i, v);
uninitialized_fill(x, a, a + s, v);
