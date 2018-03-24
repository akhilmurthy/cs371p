// ---------------------------------------
// projects/c++/allocator/RunAllocator.c++
// Copyright (C) 2018
// Glenn P. Downing
// ---------------------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <fstream>  // ifstream
#include <iostream> // cout, endl, getline
#include <string>   // s

#include "Allocator.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // replace!
    ifstream f("RunAllocator.out");
    string   s;
    while (getline(f, s))
        cout << s << endl;

    // read  from stdin,  redirect from RunDarwin.in
    // write to   stdout, redirect to   RunDarwin.out

    return 0;}
