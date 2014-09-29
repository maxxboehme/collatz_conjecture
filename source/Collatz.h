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

/**
 * returns min index and max index of range cache
 * @param min minimum of range
 * @param max maximum of range
 * @return a pair of ints, representing the beginning and end of a range for range cache, [i, j]
 */
std::pair<int, int> range_index(int min, int max);

/**
 * maximum length cycle for indexes in range cache
 * @param minIdex minimum index
 * @param maxIndex maximum index
 * @return an unsigned int with is the maximum cycle lenth found between given ranges.
 */
unsigned int max_cached(int minIndex, int maxIndex);

/**
 * optimization
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
unsigned long eval (int i, int j);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
unsigned long collatz_eval (int i, int j);


// -------------
// collatz_cycle
// -------------

/**
 * @param n the number to calulate cycles on, has to be positive
 * @reutrn the cycle length for given number
 */
unsigned long collatz_cycle (unsigned long n);

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
