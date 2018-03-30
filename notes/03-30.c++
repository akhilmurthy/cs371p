// -----------
// Fri, 30 Mar
// -----------

vector<T> f (...) {
    vector<T> y(10000); // O(n), vector(int)
    ...
    return y;}          // O(n), vector(vector)

int main () {
    vector<T> x; // O(1)
    ...
    x = f(...);  // O(1), =(vector&&)
    vector<T> y(...);
    x = y;       // O(n), =(const vector&)
