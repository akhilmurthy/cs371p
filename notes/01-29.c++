// -----------
// Mon, 29 Jan
// -----------

/*
black box vs white box testing
meta cache
exceptions
*/

/*
unit tests (white) vs acceptance tests (black)
*/

/*
lazy vs eager cache
meta cache
*/

/*
cache of ranges, not individual values
1-1000
1000-2000
2000-3000
3000-4000
...
*/

/*
mcl(1500, 3500)
look up 2000 to 3000
still compute 1500 to 2000 and 3000 to 3500
*/

/*
assertions don't handle user errors well
exceptions do
want to motivate exceptions, by pretending I don't have them
C doesn't have exceptions
*/

int f (...) {
    ....
    if (<something wrong>)
        return <special value>
    ...

int g (...) {
    ...
    int i = f(...)
    if (i = <special value>)
        <something wrong>
    ...

...
...g(...)...
...

int f (..., int& j2) {
    ....
    if (<something wrong>)
        j2 = <special value>
    ...

int g (...) {
    ...
    int j = 0
    int i = f(..., j)
    if (j = <special value>)
        <something wrong>
    ...

...
...g(...)...
...

int h;

int f (...) {
    ....
    if (<something wrong>)
        h = <special value>
    ...

int g (...) {
    ...
    h = 0
    int i = f(...)
    if (h == <special value>)
        <something wrong>
    ...

...
...g(...)...
...

/*
how can functions communicate with each other?
1. using the return
2. using a parameter by address or by reference
3. using a global variable
*/

// Java

int i = 2;
Integer x;
x = new Integer(0);

int f (...) {
    ....
    if (<something wrong>)
        throw Tiger(...);   // throw always copies what it throws
    ...

int g (...) {
    ...
    try {
        ...
        int i = f(...)
        ...
//  catch (Mammal e)       // double copy and possible slice, not good
//      <something wrong>
//  catch (Mammal* p)      // possible memory leak, not good
//      <something wrong>
    catch (Mammal& r)      // always catch by reference
        <something wrong>
    ...

...
...g(...)...
...

/*
exception scenarios
1. no exception was thrown, no catch block was run
2. an exception was thrown, caught in the caller, only catch code can run next, followed by normal code again
3. an exception was thrown, not caught in the caller, leading us to look for the caller of the caller
*/

// Java: objects only on the heap, not on the stack

Mammal z;

Mammal x = new Mammal();
Tiger  y = new Tiger();

y = x; // not ok
x = y;

// C++: objects on the heap or the stack

Mammal  x;
Mammal* p = new Mammal();

Tiger y;

y = x; // not ok
x = y;
