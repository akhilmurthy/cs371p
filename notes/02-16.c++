// -----------
// Fri, 16 Feb
// -----------

template <typename FI, typename T>
void fill (FI b, FI e, const T& c) {
    while (b != e) {
        *b = c;
        ++b;}}

template <typename II, typename OI>
OI copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}
