#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

// #define TEST1
// #define TEST2
// #define TEST3
// #define TEST4
// #define TEST5
// #define TEST6

#ifdef TEST1
void test1 () {
    assert(my_strcmp("",    "")    == 0);}
#endif

#ifdef TEST2
void test2 () {
    assert(my_strcmp("abc", "abc") == 0);}
#endif

#ifdef TEST3
void test3 () {
    assert(my_strcmp("abc", "ab")  >  0);}
#endif

#ifdef TEST4
void test4 () {
    assert(my_strcmp("abc", "aba") >  0);}
#endif

#ifdef TEST5
void test5 () {
    assert(my_strcmp("ab",  "abc") <  0);}
#endif

#ifdef TEST6
void test6 () {
    assert(my_strcmp("aba", "abc") <  0);}
#endif

int main () {
    cout << "StrCmp.c++" << endl;
    int n;
    cin >> n;
    switch (n) {
        #ifdef TEST1
        case 1:
            test1();
            break;
        #endif

        #ifdef TEST2
        case 2:
            test2();
            break;
        #endif

        #ifdef TEST3
        case 3:
            test3();
            break;
        #endif

        #ifdef TEST4
        case 4:
            test4();
            break;
        #endif

        #ifdef TEST5
        case 5:
            test5();
            break;
        #endif

        #ifdef TEST6
        case 6:
            test6();
            break;
        #endif

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}
