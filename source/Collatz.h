#ifndef __Collatz_h__
#define __Collatz_h__

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <utility>  // pair

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param r an std::istream
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
std::pair<int, int> collatz_read (std::istream& r);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);


// -------------
// collatz_cycle
// -------------

/**
 * @param n the number to calulate cycles on, has to be positive
 * @reutrn the cycle length for given number
 */
int collatz_cycle (int n);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an std::istream
 * @param w an std::ostream
 */
void collatz_solve (std::istream& r, std::ostream& w);

#endif // Collatz_h
