// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

#include "Collatz.h"

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
    int i, j;
    i = j = 0;
    r >> i >> j;
    return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
   int min = i;
   int max = j;
   int maxCycles = 0;
   for(int num = min; num <= max; num++){
      int cycle = collatz_cycle(num);
      if(cycle > maxCycles){
          maxCycles = cycle;
      }
   }
   return maxCycles;
}

int collatz_cycle(int n){
   int cycle = 1;
   while(n != 1){
      if(n & 1){
         n = n + (n >> 1) + 1;
         ++cycle;
      } else {
         n = n >> 1;
      }
      ++cycle;
   }
   return cycle;
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int i = p.first;
        const int j = p.second;
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
