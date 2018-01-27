// ----------
// StrCmp.c++
// ----------

// http://en.cppreference.com/w/c/string/byte/strcmp

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl

using namespace std;

int main () {
    cout << "StrCmp.c++" << endl;

    assert(strcmp("",    "")    ==  0);
    assert(strcmp("abc", "abc") ==  0);
    assert(strcmp("abc", "aba") ==  1);
    assert(strcmp("aba", "abc") == -1);
    assert(strcmp("abc", "ab")  ==  1);
    assert(strcmp("ab",  "abc") == -1);

    cout << "Done." << endl;
    return 0;}
