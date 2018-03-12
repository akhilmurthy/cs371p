// ---------
// Hello.c++
// ---------

// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html
// http://en.cppreference.com

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Nothing to be done." << endl;
    return 0;}

/*
Developed in 1978 by Bjarne Stroustrup of Denmark.
C++ is procedural, object-oriented, statically typed, and not garbage collected.

C++98
C++03
C++11
C++14
C++17



% which g++-7
/usr/local/bin/g++-7



% g++-7 --help
...



% g++-7 --version
g++-7 (Homebrew GCC 7.2.0) 7.2.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.



% g++-7 -pedantic -std=c++14 -Wall -Weffc++ -Wextra Hello.c++ -o Hello



% ./Hello
Nothing to be done.
*/
