// -----------
// Mon, 30 Apr
// -----------

/*
1. how many are there
    one per template flavor of the class
2. when are they allocated
    on program entry
3. when are they initialized
    on program entry, before main()
4. what is their lifetime
    lifetime of the program
5. what is their scope
    the methods of A and children of A depending on access
*/

// A.h
template <typename T>
struct A {
    static T i;}; // C++ yes, Java no

template <typename T>
T A<T>::i = g(...);

int main () {
    cout << (&A<int>::i == &A<int>::i);    // true
    cout << (&A<int>::i == &A<double>::i); // doesn't compile

template <typename T>
struct B {
    static int i;}; // C++ yes, Java no

template <typename T>
int B<T>::i = g(...);

int main () {
    cout << (&B<int>::i == &B<int>::i);    // true
    cout << (&B<int>::i == &B<double>::i); // false

int i;
double d;
cout << (&i == &d); // I don't think it compiles

struct A {
    static int c = 0;

    A () {
        ++c;}

    ~A() {
        --c;}};

int A::c;

int main () {
    cout << A::c; // 0

    {
    A x;
    cout << A::c; // 1

    A y;
    cout << A::c; // 2
    }

    cout << A::c; // 0



vector<CC> x(10, CC(...));
vector<FC> x(10, FC(...));

vector<AC> x(10, CC(...)); // not ok

vector<AC*> x(10, new CC(...)); // not ok

vector<AC*> x(10);
loop
    x[i] = new CC(...);

vector<C> x(10, C(new CC(...)));

Shape x = new Circle(...);
Cell  y = new CC(...);

y.evolve(...);
cout << y.area();


Shape2 x = new Circle(...);
cout << (*x).area();
cout << x.operator*().area()

cout << x->area();
cout << x.operator->()->area()

Shape2 y = x;
