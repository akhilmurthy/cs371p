// -----------
// Wed,  7 Feb
// -----------

/*
l-values vs. r-values
argument passing
*/

int i;
i = ...;
2 = ...; // not ok

/*
valid on the left-hand-side of assignment, you're an l-value
if not, you're an r-value
*/

int i = 2;
int j = 3;
int k = (i + j);
k = (2 + 3);

i + j; // not ok, + produces an expression (can't standalone)

/*
+ takes two r-values, returns an r-value
*/

++(i + j); // not ok

int i = 2;
int j = 3;
int k = (i << j);
k = (2 << 3);

++(i << j); // not ok

/*
<< takes two r-values, returns an r-value
*/

int i = 2;
int j = 3;

int k; // statement (can standalone)

i += j; // statement
i += 2;
3 += 2; // not ok

/*
+= takes an l-value on the left and an r-value on the right
+= in C++ returns an l-value; C and Java return an r-value; Python returns nothing
*/

int i = 2;
int j = 3;
int k = (i += j); // C, C++, Java: ok; Python: not ok

(i += j) = k; // C++: ok; C, Java, Python: not ok

++(i += j);

void f (int v) { // an r-valiue
    ++v;}

int main () {
    int i = 2;
    f(i);
    cout << i; // 2
    f(185);

void g (int* p) { // an int by address
    <check on the validity of p>
    ++*p;
    int m = 3;
    p = &m;

int main () {
    int j = 3;
    g(j);      // not ok
    g(&j);
    int* q = &j;
    g(q);
    cout << j; // 4
    g(185);    // not ok
    g(0);      // ok!!!
    g(nullptr); // the same as 0

void h (int& r) { // an int by reference, needs an l-value
    ++*r;         // not ok
    ++r;
    int m = 2;
    // is there a way to connect r to m? no
    r = m; // that's just changing k

int main () {
    int k = 4;
    h(&k);     // not ok
    h(k);
    cout << k; // 5
    h(185);    // not ok
    h(0);      // not ok

/*
a big part of OO languages is to change
certain classes of error from being runtime errors
to compile time errors
*/
