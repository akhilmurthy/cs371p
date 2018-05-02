// -----------
// Wed, 2  May
// -----------

class Cell {
    private:
        ...
    public:
        Cell (AbstractCell* p) {...}

        Cell (const Cell& rhs) {...clone()...}

vector<AC*> x(10, new CC(...)); // not useful
vector<C>   x(10, new CC(...));

/*
CC(...), once
C(...), once
C(C), 10 times
CC(CC), 10 times
~C(), once
~CC(), once
*/

/*
copy on write (COW)
*/

CC c1 = new CC(...);

CC c2 = c1;

CC c2 = c1;

CC c4 = new C(...);

CC c5 = c4;

c4.setAlive();
c4.setDead();
