// ----------
// StrCmp.c++
// ----------

// http://en.cppreference.com/w/c/string/byte/strcmp

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl

using namespace std;

void test () {
    assert(strcmp("",    "")    == 0);
    assert(strcmp("abc", "abc") == 0);
    assert(strcmp("abc", "ab")  >  0);
    assert(strcmp("abc", "aba") >  0);
    assert(strcmp("ab",  "abc") <  0);
    assert(strcmp("aba", "abc") <  0);}

int main () {
    cout << "StrCmp.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
