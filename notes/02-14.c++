// -----------
// Wed, 14 Feb
// -----------

template <typename T1, typename T2>
bool equal (T1 b, T1 e, T2 x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

void test2 () {
    const int  a[] = {2, 3, 4};
    const long b[] = {0, 2, 3, 4, 0};
    assert(equal(a, a + 3, b + 1));}  // T1 -> int*; T2 -> long*

void test4 () {
    const list<int> x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
    assert(equal(begin(x), end(x), begin(y) + 1));} // T1 -> list<int>::iterator
                                                    // T2 -> vector<int>::iterator
// operators that T1 needs to respond to:
!=
++
*

// operators that T2 needs to respond to:
++
*

// input iterator
==, !=, ++, * (read-only)

// output iterator
++, * (write-only)

// forward iterator
==, !=, ++, * (read/write)

// bidirectional iterator
<forward iterator>, --

// random access iterator
<bidirectional iterator>, + int, - int, [], <, <=, >, >=

/*
when I define an algorithm, choose the weakest possible iterator
when I define a container, choose the strongest possible iterator
*/

copy
input, output

fill
forward

reverse
bidirectional

sort
random access

istream
input

ostream
output

forward_list
forward

list
bidirectional

vector
random access

interface list
    get(index)

ArrayList
LinkedList
DequeList




















