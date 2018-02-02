// -----------
// Fri,  2 Feb
// -----------

char a[] = "abc";
char b[] = "abc";
cout << (a == b);     // false, identity comparison
cout << strcmp(a, b); // 0, content comparison

string s = "abc";
string t = "abc";
cout << (&s == &t); // false
cout << (s == t);   // true

// Java

String s = new String("abc");
String t = new String("def");
s.o.p(s == t);                // false
s.o.p(s.equals(t));           // true

// C++

void f (string t) {
    ...}

int main () {
    string s = "abc";
    f(s);
    f(string("abc"));
    f("abc");
    f(2);             // not ok

// Java

class Weihan extends Throwable {}

class T {
    ...
    throw new Weihan();

// C++

class Weihan {}

class T {
    ...
    throw new Weihan();

/*
two tokens: *, &
two contexts: next to a type, next to a variable
*/

int i = 2;
int j = i;
++j;
cout << i;   // 2

int  i = 2;
int* p = i;  // not ok
int* p = &i;
//++p;       // compiles, but in this example unreasonable
++*p
cout << i;   // 3

int j = 4;
p = &j;

int  i = 2;
int& r = &i; // not ok
int& r = i;
++i;
cout << r;   // 3
++r;
cout << i;   // 4
