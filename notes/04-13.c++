// -----------
// Fri, 13 Apr
// -----------

vector<int> x(10, 2);

Life<T>
Cell
AbstractCell
    ConwayCell
    FredkinCell

class AbstractCell {
    public:
        virtual AbstractCell* clone () const {
            return nullptr;}};

class ConwayCell : public AbstractCell {
    public:
        AbstractCell* clone () const {
            return new ConwayCell(*this);}};

class Cell {
    private:
        AbstractCell* _p;
    public:
        Cell (const Cell& rhs) :
            _p (rhs._p->clone())
            {}

template <typename T>
class Life {
    private:
        vector<vector<T>> _g;
    public:
        Life (int r, int c, const T& v) :
            _g (r, vector<T>(c, v))
            {}};

int main () {
    Life<ConwayCell>  x(10, 20, ConwayCell());
    Life<FredkinCell> y(10, 20, FredkinCell());
    Life<Cell>        z(10, 20, Cell(new FredkinCell()));

/*
by default C++  exhibits static  binding
by default Java exhibits dynamic binding
*/

struct A {
    void f ()
        {}

    virtual inline void g ()
        {}};

struct B : A {
    void f ()
        {}

    void g ()
        {}};

struct C : B {
    ...

int main () {
    A x;
    x.f(); // A::f
    x.g(); // A::g

    B y;
    y.f(); // B::f
    y.g(); // B::g

    A* p;
    if (...)
        p = new A;
    else
        p = new B;
    p->f();       // A::f
    p->g();       // A::g or B::g, but I won't know until I run
    p->A::g();

struct A {
    A () {
        f();}
    virtual void f () {}

    virtual ~A() {
        f();}};

struct B : A {
    void f () {}};

struct C : B {
    void f () {}};

int main () {
    A* p = new C; // A::f
    p->f();
    delete p;     // A::f

/*
four cases in which virtual will not result in dynamic binding
    1. on an object
    2. with the scope operator
    3. in a constructor
    4. in a destructor
*/
