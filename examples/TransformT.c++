// --------------
// TransformT.c++
// --------------

// http://en.cppreference.com/w/cpp/algorithm/transform

#include <algorithm>  // transform, equal
#include <functional> // negate
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II, typename OI, typename UF>
OI my_transform (II b, II e, OI x, UF f) {
    while (b != e) {
        *x = f(*b);
        ++b;
        ++x;}
    return x;}

using Transform_List_Signature = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator, function<int (int)>)>;

struct Transform_List_Fixture : TestWithParam<Transform_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Transform_List_Instantiation,
    Transform_List_Fixture,
    Values(
           transform<list<int>::const_iterator, vector<int>::iterator, function<int (int)>>,
        my_transform<list<int>::const_iterator, vector<int>::iterator, function<int (int)>>));

TEST_P(Transform_List_Fixture, test) {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    const function<int (int)> f = [] (int x) -> int {return x * x;};
    vector<int>::iterator     p = GetParam()(begin(x), end(x), begin(y) + 1, f);
    ASSERT_EQ(p, begin(y) + 4);
    ASSERT_TRUE(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}
