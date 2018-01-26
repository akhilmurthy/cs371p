// -----------
// Fri, 26 Jan
// -----------

/*
assertions not good for
    testing
    user errors
*/

/*
unit testing
coverage
exercise
*/

/*
1. run as is, confirm success
2. fix the tests
3. run, confirm failure
4. fix the code
5. run, confirm success
*/

for (int i = 0; i != s; ++i)
    // <do something>

// vs.

for (int i = 0; i != s; i++)
    // <do something>

{
int i = 0;
while (i != s) {
    // <do something>
    ++i;}
}

// vs.

{
int i = 0;
while (i != s) {
    // <do something>
    i++;}
}

int i = 2;

int j = ++i;
// vs.
int j = i++;

f(++i);
// vs.
f(i++);
