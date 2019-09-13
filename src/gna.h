#ifndef __gna_h__
#define __gna_h__

#include "../src/util.h"
#include "time.h"
#include "math.h"

ul_int seed = 0;

double gna();
double sgna(int nseed);
ul_int gnai(int length);

double gna() {
  ul_int multiplier, module;

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

/** Generates a pseudo-random number with a given number of digits
 * @param length is the number of digits
 * @return n, the random number
 */
ul_int gnai(int length) {
  if (length < 1) return 0;

  ul_int n, c;
  u_int r, q, i, j;

  n = 0; c = 0;
  r = length%6;
  q = length/6;

  for (i = 0; i < q; i++) {
    u_int p = (u_int) (gna() * 1e6);
    while (p == 0 || p < 1e5) p = (u_int) (gna() * 1e6);
    n += (ul_int) (p * pow(10, 6*i));
  }

  for (int j = 0; j < r; j++) {
    u_int p = (u_int) (gna() * 1e1);
    while (p == 0) p = (u_int) (gna() * 1e1);
    c += (ul_int) (p * pow(10, j));
  }

  n += (ul_int) (c * pow(10, 6*i));
  return n;
}

ul_int gnab(u_int n_bits) {
  if (n_bits < 1) return 0;

  ul_int upper = get_upper(n_bits);
  ul_int lower = get_upper(n_bits-1);

  return gna() * (upper - (lower+1)) + (lower+1);
}

#endif