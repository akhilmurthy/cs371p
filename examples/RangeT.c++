// ----------
// RangeT.c++
// ----------

#include "gtest/gtest.h"

using namespace std;

template <typename T>
class Range {
    private:
        T _b;
        T _e;

    public:
        class iterator {
            private:
                T _v;

            public:
                iterator (const T& v) :
                        _v (v)
                    {}

                bool operator == (const iterator& rhs) const {
                    return (_v == rhs._v);}

                bool operator != (const iterator& rhs) const {
                    return !(*this == rhs);}

                T operator * () const {
                    return _v;}

                iterator& operator ++ () {
                    ++_v;
                    return *this;}

                iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        Range (const T& b, const T& e) :
                _b (b),
                _e (e)
            {}

        iterator begin () const {
            return _b;}

        iterator end () const {
            return _e;}};

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

TEST(RangeFixture, test1) {
    const Range<int> x(2, 2);
    const Range<int>::iterator b = begin(x);
    const Range<int>::iterator e = end(x);
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test2) {
    Range<int> x(2, 3);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    Range<int>::iterator& y = ++b;
    ASSERT_EQ(&y, &b);
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test3) {
    Range<int> x(2, 4);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(3, *b);
    b++;
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test4) {
    Range<int> x(2, 5);
    ASSERT_TRUE(my_equal(begin(x), end(x), begin({2, 3, 4})));}

TEST(RangeFixture, test5) {
    Range<int> x(2, 5);
    int s = 0;
    for (int v : x)
        s += v;
    ASSERT_EQ(s, 9);}
