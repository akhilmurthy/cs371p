// ----------
// EqualT.c++
// ----------

// http://en.cppreference.com/w/cpp/algorithm/equal

#include <algorithm>  // equal
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

TEST(EqualFixture, test1) {
    const int a[] = {2, 3, 4};
    const int b[] = {0, 2, 3, 4, 0};
    ASSERT_FALSE(   equal(a, a + 3, b));
    ASSERT_FALSE(my_equal(a, a + 3, b));}

TEST(EqualFixture, test2) {
    const int a[] = {2, 3, 4};
    const int b[] = {0, 2, 3, 4, 0};
    ASSERT_TRUE(   equal(a, a + 3, b + 1));
    ASSERT_TRUE(my_equal(a, a + 3, b + 1));}

TEST(EqualFixture, test3) {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
    ASSERT_FALSE(   equal(begin(x), end(x), begin(y)));
    ASSERT_FALSE(my_equal(begin(x), end(x), begin(y)));}

TEST(EqualFixture, test4) {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
    ASSERT_TRUE(   equal(begin(x), end(x), begin(y) + 1));
    ASSERT_TRUE(my_equal(begin(x), end(x), begin(y) + 1));}
