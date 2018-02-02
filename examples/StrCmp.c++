// ----------
// StrCmp.c++
// ----------

// http://en.cppreference.com/w/c/string/byte/strcmp

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl

using namespace std;

void test1 () {
    assert(strcmp("",    "")    == 0);}

void test2 () {
    assert(strcmp("abc", "abc") == 0);}

void test3 () {
    assert(strcmp("abc", "ab")  >  0);}

void test4 () {
    assert(strcmp("abc", "aba") >  0);}

void test5 () {
    assert(strcmp("ab",  "abc") <  0);}

void test6 () {
    assert(strcmp("aba", "abc") <  0);}

int main () {
    cout << "StrCmp.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "Done." << endl;
    return 0;}
