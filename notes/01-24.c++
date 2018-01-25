// -----------
// Wed, 24 Jan
// -----------

/*
if the input is odd: 3n + 1
*/

/*
(3n + 1) / 2
3n/2 + 1/2
n + n/2 + 1/2, because / is integer division
n + n/2 + 1
n + (n >> 1) + 1
*/

b = 10
e = 100
m = 51                       // b is <= m
mcl(10, 100) == mcl(51, 100)

/*
the numbers in the range [10, 50] all map to numbers in the range [51, 100] by repeated doubling
*/

10, 20, 40, 80
25, 50, 100
30, 60
15, 30, 60

b = 200
e = 300
m = 151 // b is not <= m

/*
workflow
more optimizations for the Collatz problem
*/

/*
unit tests test individual parts of the solution
acceptance tests test the overall behavior of the program
*/

/*
1 to 10
let's have a cache in the form of an array (memoization)
input is from 1 to 1,000,000
let's make the array 1,000,000
start by only remembering the values asked for
improve that by remembering the intermediate values
*/

/*
lazy cache
do it in response to reads
vs.
eager cache
do it before reads
*/
