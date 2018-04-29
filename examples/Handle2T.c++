// ------------
// Handle2T.c++
// ------------

#include <algorithm> // swap
#include <typeinfo>  // bad_cast
#include <utility>   // !=

#include "gtest/gtest.h"

using namespace std;
using rel_ops::operator!=;

class AbstractShape {
    friend bool operator == (const AbstractShape& lhs, const AbstractShape& rhs) {
        return lhs.equals(rhs);}

    friend istream& operator >> (istream& lhs, AbstractShape& rhs) {
        return rhs.read(lhs);}

    friend ostream& operator << (ostream& lhs, const AbstractShape& rhs) {
        return rhs.write(lhs);}

    private:
        int _x;
        int _y;

    protected:
        AbstractShape& operator = (const AbstractShape&) = default;

        virtual bool     equals (const AbstractShape& rhs) const = 0;
        virtual istream& read   (istream&             in)        = 0;
        virtual ostream& write  (ostream&             out) const = 0;

    public:
        AbstractShape (int x, int y) :
                _x (x),
                _y (y)
            {}

        AbstractShape          (const AbstractShape&) = default;
        virtual ~AbstractShape ()                     = default;

        virtual double         area  () const = 0;
        virtual AbstractShape* clone () const = 0;

        void move (int x, int y) {
            _x = x;
            _y = y;}};

bool AbstractShape::equals (const AbstractShape& rhs) const {
    return (_x == rhs._x) && (_y == rhs._y);}

istream& AbstractShape::read (istream& in) {
    return in >> _x >> _y;}

ostream& AbstractShape::write (ostream& out) const {
    return out << _x << " " << _y;}

class Circle : public AbstractShape {
    friend bool operator == (const Circle& lhs, const Circle& rhs) {
        return lhs.AbstractShape::equals(rhs) && (lhs._r == rhs._r);}

    friend istream& operator >> (istream& lhs, Circle& rhs) {
        return rhs.read(lhs);}

    friend ostream& operator << (ostream& lhs, const Circle& rhs) {
        return rhs.write(lhs);}

    private:
        int _r;

    protected:
        bool equals (const AbstractShape& rhs) const override {
            if (const Circle* const p = dynamic_cast<const Circle*>(&rhs))
                return AbstractShape::equals(rhs) && (_r == p->_r);
            return false;}

        istream& read (istream& in) override {
            return AbstractShape::read(in) >> _r;}

        ostream& write (ostream& out) const override {
            return AbstractShape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                AbstractShape (x, y),
                _r            (r)
            {}

        Circle             (const Circle&) = default;
        ~Circle            ()              = default;
        Circle& operator = (const Circle&) = default;

        double area () const override {
            return 3.14 * _r * _r;}

        Circle* clone () const override {
            return new Circle(*this);}

        int radius () const {
            return _r;}};

template <typename T>
class Handle {
    friend bool operator == (const Handle& lhs, const Handle& rhs) {
        if ((lhs.get() == nullptr) && (rhs.get() == nullptr))
            return true;
        if ((lhs.get() == nullptr) || (rhs.get() == nullptr))
            return false;
        return (*lhs.get() == *rhs.get());}

    public:
        typedef T           value_type;
        typedef value_type* pointer;
        typedef value_type& reference;

    private:
        pointer _p;

    public:
        Handle (pointer p) :
                _p (p)
            {}

        Handle (const Handle& rhs) :
                _p ((rhs._p == nullptr) ? nullptr : rhs._p->clone())
            {}

        Handle& operator = (const Handle& rhs) {
            Handle that(rhs);
            swap(that);
            return *this;}

        ~Handle () {
            delete _p;}

        reference operator * () const {
            return *get();}

        pointer operator -> () const {
            return get();}

        pointer get () const {
            assert(_p != nullptr);
            return _p;}

        void swap (Handle& rhs) {
            std::swap(_p, rhs._p);}};

using Shape       = Handle<      AbstractShape>;
using const_Shape = Handle<const AbstractShape>;

TEST(HandleFixture, test_1) {
    const_Shape x = new Circle(2, 3, 4);
//  x->move(5, 6);                                                           // doesn't compile
    ASSERT_EQ(x->area(), 3.14 * 4 * 4);
//  x->radius();                                                             // doesn't compile
    if (const Circle* const p = dynamic_cast<const Circle*>(x.operator->()))
        ASSERT_EQ(p->radius(), 4);
    try {
        const Circle& r = dynamic_cast<const Circle&>(x.operator*());
        ASSERT_EQ(4, r.radius());}
    catch (const bad_cast& e) {
        assert(false);}}

TEST(HandleFixture, test_2) {
    Shape x = new Circle(2, 3, 4);
    x->move(5, 6);
    ASSERT_EQ(x,         new Circle(5, 6, 4));
    ASSERT_EQ(x->area(), 3.14 * 4 * 4);
//  x.radius();                                                              // doesn't compile
    if (const Circle* const p = dynamic_cast<const Circle*>(x.operator->()))
        ASSERT_EQ(p->radius(), 4);
    try {
        const Circle& r = dynamic_cast<const Circle&>(x.operator*());
        ASSERT_EQ(r.radius(), 4);}
    catch (const bad_cast& e) {
        assert(false);}}

TEST(Handle_Fixture, test_3) {
    const Shape x = new Circle(2, 3, 4);
          Shape y = x;
    ASSERT_EQ(x, y);
    y->move(5, 6);
    ASSERT_EQ(x,         new Circle(2, 3, 4));
    ASSERT_EQ(y,         new Circle(5, 6, 4));
    ASSERT_EQ(y->area(), 3.14 * 4 * 4);}

TEST(Handle_Fixture, test_4) {
    const Shape x = new Circle(2, 3, 4);
          Shape y = new Circle(2, 3, 5);
    ASSERT_NE(x, y);
    y = x;
    ASSERT_EQ(x, y);
    y->move(5, 6);
    ASSERT_EQ(x,         new Circle(2, 3, 4));
    ASSERT_EQ(y,         new Circle(5, 6, 4));
    ASSERT_EQ(y->area(), 3.14 * 4 * 4);}
