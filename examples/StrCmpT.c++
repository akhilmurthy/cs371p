// -----------
// StrCmpT.c++
// -----------

// http://en.cppreference.com/w/c/string/byte/strcmp

#include <cstring>    // strcmp
#include <functional> // function

#include "gtest/gtest.h"

int my_strcmp (const char* a, const char* b) {
    while ((*a != 0) && (*a == *b)) {
        ++a;
        ++b;}
    return (*a - *b);}

using namespace std;
using namespace testing;

using StrCmpSignature = function<int (const char*, const char*)>;

struct StrCmpFixture : TestWithParam<StrCmpSignature> {};

INSTANTIATE_TEST_CASE_P(
    StrCmpInstantiation,
    StrCmpFixture,
    Values(
           strcmp,
        my_strcmp));

TEST_P(StrCmpFixture, test_1) {
    ASSERT_EQ(GetParam()("", ""), 0);}

TEST_P(StrCmpFixture, test_2) {
    ASSERT_EQ(GetParam()("abc", "abc"), 0);}

TEST_P(StrCmpFixture, test_3) {
    ASSERT_GT(GetParam()("abc", "ab"), 0);}

TEST_P(StrCmpFixture, test_4) {
    ASSERT_GT(GetParam()("abc", "aba"), 0);}

TEST_P(StrCmpFixture, test_5) {
    ASSERT_LT(GetParam()("ab", "abc"), 0);}

TEST_P(StrCmpFixture, test_6) {
    ASSERT_LT(GetParam()("aba", "abc"), 0);}
