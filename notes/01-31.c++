// -----------
// Wed, 31 Jan
// -----------

int i = 2;
int j = ++i;

int k = ++2;       // not ok
int k = ++(i + j); // not ok

int i = 2;
++i;
++++i;

int i = 2;
i++;
i++++;     // not ok
