// ------------------
// RangeIteratorT.c++
// ------------------

#include "gtest/gtest.h"

using namespace std;

template <typename T>
class RangeIterator {
    private:
        T _v;

    public:
        RangeIterator (const T& v) :
                _v (v)
            {}

        bool operator == (const RangeIterator& rhs) const {
            return (_v == rhs._v);}

        bool operator != (const RangeIterator& rhs) const {
            return !(*this == rhs);}

        T operator * () const {
            return _v;}

        RangeIterator& operator ++ () {
            ++_v;
            return *this;}

        RangeIterator operator ++ (int) {
            RangeIterator x = *this;
            ++*this;
            return x;}};

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

TEST(RangeIteratorFixture, test_1) {
    const RangeIterator<int> b = 2;
    ASSERT_EQ(*b, 2);}

TEST(RangeIteratorFixture, test_2) {
    const RangeIterator<int> b = 2;
    const RangeIterator<int> e = 2;
    ASSERT_EQ(b, e);}

TEST(RangeIteratorFixture, test_3) {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 3;
    ASSERT_NE(b,  e);
    ASSERT_EQ(*b, 2);
    RangeIterator<int>& x = ++b;
    ASSERT_EQ(&x, &b);
    ASSERT_EQ(b,  e);}

TEST(RangeIteratorFixture, test_4) {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 4;
    ASSERT_NE(b,  e);
    ASSERT_EQ(*b, 2);
    ++b;
    ASSERT_NE(b,  e);
    ASSERT_EQ(*b, 3);
    RangeIterator<int> x = b++;
    ASSERT_NE(&x, &b);
    ASSERT_EQ(b,  e);}

TEST(RangeIteratorFixture, test_5) {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 5;
    ASSERT_TRUE(my_equal(b, e, begin({2, 3, 4})));}
