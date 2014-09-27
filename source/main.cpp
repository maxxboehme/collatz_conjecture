// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout

#include "Collatz.h"

// ----
// main
// ----

int main (int argc, char* argv[]) {
    collatz_solve(std::cin, std::cout);
    return 0;
}
