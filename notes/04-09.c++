// -----------
// Mon,  9 Apr
// -----------

/*
John Conway
mathematician at Oxford

Game of Life

describing Conway Cell

rectangular grid of cells

cells have two states: dead and alive

rules for transitioning between those state

need to define of neighborhood

adjacent cells, including diagonals

possible postions for a cell
    1. corner: 3
    2. edge: 5
    3. anywhere else: 8

transition rules:
    if alive and 2 or 3 neighbor cells alive, stay alive
    if dead and 3 neighbor cells alive, become alive

alive: *
dead: .

.....
..*..
..*..
..*..
.....

5x5 = 25 cells
3 alive
22 dead

.....
.....
.***.
.....
.....

60x100 = 6000 cells

.....
..*..
..*..
..*..
..*..
..*..
.....
<do it again, 6 more times>

gen   0:  35
gen 283: 492
gen 323: 192
*/

Darwin x(10, 20);

Life<ConwayCell> y(30, 40);

Life<FredkinCell> z(50, 60);

Life<T>

AbstractCell
    ConwayCell
    FredkinCell

ConwayCell x(...);
Life<ConwayCell> y(10, 20, x); // CC(CC), 200 times

FredkinCell x(...);
Life<FredkinCell> y(10, 20, x); // FC(FC), 200 times

ConwayCell x(...);
Life<AbstractCell> y(10, 20, x); // C(C), 200 times; doesn't work

ConwayCell x(...);
Life<AbstractCell*> y(10, 20 &x); // of CC: <nothing>

ConwayCell x(...);
Life<AbstractCell*> y(10, 20); // still no good
y.fill(&x);

Life<AbstractCell*> y(10, 20);
// loop
    y[i][j] = new CC(...); // CC(...), 200 times

// <do the simulation>

// loop
    delete y[i][j]

Cell x(new ConwayCell(...));  // Cell acts like a handle or smart pointer
Cell y(new FredkinCell(...));

x = y;

class Cell {
    private:
        AbstractCell* _p;
    public:
        Cell (AbstractCell* p) {
            _p = p;}
        ~Cell () {
            delete _p;}
