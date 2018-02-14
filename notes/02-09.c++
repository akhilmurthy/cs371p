// -----------
// Fri,  9 Feb
// -----------

int x = 2;
int y = 3;

x += y;
x += 3;
2 += 3; // not ok

int z = (x += y);
++(x += y);

++++x;
x++++; // not ok

/*
consts
*/

int i;     // initialization not required
int j = 4;
i = 2;
++i;

const int ci;     // not ok
const int ci = 2;
const int cj = 3;
++ci;             // not ok

int* p;
p = &i;
++*p;
cout << i; // 4
p = &ci;   // not ok
++*p;

const int* pc;
pc = &ci;
++*pc;                         // not ok
pc = &cj;
pc = &i;
++*pc;                         // not ok
int* q = const_cast<int*>(pc);

int* const cp;       // not ok
int* const cp = &ci; // not ok
int* const cp = &i;
++*cp;
cp = &j;             // not ok

const int* const cpc;
const int* const cpc = &ci;
cpc = &cj;                  // not ok
const int* const cqc = &i;
++*cpc;                     // not ok
++*cqc;                     // not ok

int* const p = new int[100];
++p;
delete [] p;
