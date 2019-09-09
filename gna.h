#ifndef __gna_h__
#define __gna_h__

#include "util.h"
#include "time.h"

unsigned long int seed = 0;

double gna();
double sgna(int nseed);
// int gna(int length, int k);

double gna() {
  unsigned long int multiplier, module;

  if (seed == 0) seed = time(NULL);

  multiplier = 46341;
  module = 2147483647;
  seed = seed * multiplier % module;
  
  return (double) seed / (double) module;
}

double sgna(int nseed) {
  seed = nseed;
  return gna();
}

// int gna(length, k) {
//   int n = gna(length);
  
//   while (!is_prime(n, k))
//     n = gna(length);

//   return n;
// }

#endif