// -----------
// Fri, 27 Apr
// -----------

/*
1. how many are there
    one per function invocation
2. when are they allocated
    on function entry
3. when are they initialized
    on the line
4. what is their lifetime
    lifetime of the function
5. what is their scope
    in the function, after the line
*/

void f () {
    ...
    int i = g(...);
    ...}



/*
1. how many are there
    one per program
2. when are they allocated
    on program entry
3. when are they initialized
    once, first time we get to the line
4. what is their lifetime
    lifetime of the program
5. what is their scope
    in the function, after the line
*/

void f () {
    ...
    static int i = g(...);
    ...}



/*
1. how many are there
    one per program
2. when are they allocated
    on program entry
3. when are they initialized
    once, before main()
4. what is their lifetime
    lifetime of the program
5. what is their scope
    the program
*/

// foo.c++

 int i = g(...);

void f () {
    ...}

// bar.c++

extern int i;

void h () {
    ++i;}

/*
1. how many are there
    one per program
2. when are they allocated
    on program entry
3. when are they initialized
    once, before main()
4. what is their lifetime
    lifetime of the program
5. what is their scope
    in the file
*/

// foo.c++

static int i = g(...);

void f () {
    ...}

// bar.c++

static int i;

void h () {
    ++i;}



/*
1. how many are there
    one per instance
2. when are they allocated
    when the instance is allocated
3. when are they initialized
    when the instance is initialized
4. what is their lifetime
    lifetime of the instance
5. what is their scope
    the methods of A and children of A depending on access
*/

struct A {
    int i;};
