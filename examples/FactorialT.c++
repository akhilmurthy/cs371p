// --------------
// FactorialT.c++
// --------------

#include <ctime>      // clock, clock_t, CLOCKS_PER_SEC
#include <functional> // function, multiplies
#include <iomanip>    // setprecision, setw
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;

template <typename T>
class RangeIterator {
    friend bool operator == (const RangeIterator& lhs, const RangeIterator& rhs) {
        return (lhs._v == rhs._v);}

    friend bool operator != (const RangeIterator& lhs, const RangeIterator& rhs) {
        return !(lhs == rhs);}

    private:
        T _v;

    public:
        RangeIterator (const T& v) :
                _v (v)
            {}

        T operator * () const {
            return _v;}

        RangeIterator& operator ++ () {
            ++_v;
            return *this;}

        RangeIterator operator ++ (int) {
            RangeIterator x = *this;
            ++*this;
            return x;}};

// recursive procedure
// linear recursive process
// 0.108 milliseconds
int factorial_recursion (int n) {
    assert(n >= 0);
    if (n < 2)
        return 1;
    return n * factorial_recursion(n - 1);}

int factorial_tail_recursion_aux (int n, int m) {
    assert(n >= 0);
    assert(m >= 1);
    if (n < 2)
        return m;
    return factorial_tail_recursion_aux(n - 1, n * m);}

// recursive procedure
// linear iterative process
// 0.120 milliseconds
int factorial_tail_recursion (int n) {
    assert(n >= 0);
    return factorial_tail_recursion_aux(n, 1);}

// iterative procedure
// linear iterative process
// 0.069 milliseconds
int factorial_iteration (int n) {
    assert(n >= 0);
    int v = 1;
    while (n > 1) {
        v *= n;
        --n;}
    return v;}

// iterative procedure
// linear iterative process
// 1.217 milliseconds
int factorial_accumulate_1 (int n) {
    assert(n >= 0);
    vector<int> x(n);
    RangeIterator<int> b = 1;
    RangeIterator<int> e = n + 1;
    function<int (int, int)> f = [] (int x, int y) -> int {return x * y;};
    const int v = accumulate(b, e, 1, f);
    return v;}

// iterative procedure
// linear iterative process
// 0.470 milliseconds
int factorial_accumulate_2 (int n) {
    assert(n >= 0);
    vector<int> x(n);
    RangeIterator<int> b = 1;
    RangeIterator<int> e = n + 1;
    const int v = accumulate(b, e, 1, multiplies<int>());
    return v;}

using testing::TestWithParam;
using testing::Values;

using Factorial_Signature = function<int (int)>;

struct Factorial_Fixture : TestWithParam<Factorial_Signature> {};

INSTANTIATE_TEST_CASE_P(
    Factorial_Instantiation,
    Factorial_Fixture,
    Values(
        factorial_recursion,
        factorial_tail_recursion,
        factorial_iteration,
        factorial_accumulate_1,
        factorial_accumulate_2));

TEST_P(Factorial_Fixture, test1) {
	ASSERT_EQ(GetParam()(0), 1);}

TEST_P(Factorial_Fixture, test2) {
	ASSERT_EQ(GetParam()(1), 1);}

TEST_P(Factorial_Fixture, test3) {
	ASSERT_EQ(GetParam()(2), 2);}

TEST_P(Factorial_Fixture, test4) {
	ASSERT_EQ(GetParam()(3), 6);}

TEST_P(Factorial_Fixture, test5) {
	ASSERT_EQ(GetParam()(4), 24);}

TEST_P(Factorial_Fixture, test6) {
	ASSERT_EQ(GetParam()(5), 120);}

TEST_P(Factorial_Fixture, test7) {
    const clock_t b = clock();
    for (int i = 0; i != 1000; ++i)
        GetParam()(12);
    const clock_t e = clock();
    cout << fixed << setprecision(3) << setw(5);
    cout << ((e - b) * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;}

/*
% FactorialT
Running main() from gtest_main.cc
[==========] Running 35 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 35 tests from Factorial_Instantiation/Factorial_Fixture
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test1/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test1/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test1/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test1/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test1/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test1/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test1/3
[       OK ] Factorial_Instantiation/Factorial_Fixture.test1/3 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test1/4
[       OK ] Factorial_Instantiation/Factorial_Fixture.test1/4 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test2/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test2/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test2/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test2/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test2/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test2/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test2/3
[       OK ] Factorial_Instantiation/Factorial_Fixture.test2/3 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test2/4
[       OK ] Factorial_Instantiation/Factorial_Fixture.test2/4 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test3/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test3/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test3/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test3/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test3/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test3/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test3/3
[       OK ] Factorial_Instantiation/Factorial_Fixture.test3/3 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test3/4
[       OK ] Factorial_Instantiation/Factorial_Fixture.test3/4 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test4/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test4/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test4/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test4/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test4/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test4/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test4/3
[       OK ] Factorial_Instantiation/Factorial_Fixture.test4/3 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test4/4
[       OK ] Factorial_Instantiation/Factorial_Fixture.test4/4 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test5/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test5/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test5/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test5/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test5/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test5/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test5/3
[       OK ] Factorial_Instantiation/Factorial_Fixture.test5/3 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test5/4
[       OK ] Factorial_Instantiation/Factorial_Fixture.test5/4 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test6/0
[       OK ] Factorial_Instantiation/Factorial_Fixture.test6/0 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test6/1
[       OK ] Factorial_Instantiation/Factorial_Fixture.test6/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test6/2
[       OK ] Factorial_Instantiation/Factorial_Fixture.test6/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test6/3
[       OK ] Factorial_Instantiation/Factorial_Fixture.test6/3 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test6/4
[       OK ] Factorial_Instantiation/Factorial_Fixture.test6/4 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test7/0
0.108 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test7/0 (1 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test7/1
0.120 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test7/1 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test7/2
0.069 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test7/2 (0 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test7/3
1.217 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test7/3 (2 ms)
[ RUN      ] Factorial_Instantiation/Factorial_Fixture.test7/4
0.470 milliseconds

[       OK ] Factorial_Instantiation/Factorial_Fixture.test7/4 (0 ms)
[----------] 35 tests from Factorial_Instantiation/Factorial_Fixture (3 ms total)

[----------] Global test environment tear-down
[==========] 35 tests from 1 test case ran. (3 ms total)
[  PASSED  ] 35 tests.
*/
