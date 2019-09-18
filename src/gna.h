#ifndef __gna_h__
#define __gna_h__

#include "../src/util.h"
#include "time.h"
#include "math.h"

ul_int seed = 0;
char* seed_s = NULL; // TODO - memory leak?

double gna();
double sgna(int nseed);
ul_int gnai(int length);

double gna() {
  ul_int multiplier, modulo;

  if (seed == 0) seed = time(NULL);

  multiplier = 46341;
  modulo = 2147483647;
  seed = seed * multiplier % modulo;
  
  return (double) seed / (double) modulo;
}

double sgna(int nseed) {
  seed = nseed;
  return gna();
}

void gna_i(real n) {
  integer seed, multiplier, modulo;
  inits_i(seed, multiplier, modulo, NULL);

  if (seed_s == NULL)
    set_i_ui(seed, time(NULL));
  else
    set_i_s(seed, seed_s);

  set_i_s(multiplier, "46341");
  set_i_s(modulo, "2147483647");
  mul_i(seed, seed, multiplier);
  mod_i(seed, seed, modulo);
  
  real p, q;
  inits_r(p, q, NULL);
  set_r_i(p, seed);
  set_r_i(q, modulo);

  div_r(n, p, q);
  seed_s = get_i_s(NULL, 10, seed);

  clears_i(seed, multiplier, modulo, NULL);
  clears_r(p, q, NULL);
}

void sgna_i(real n, integer nseed_i) {
  seed_s = get_i_s(NULL, 10, nseed_i);
  gna_i(n);
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

  ul_int b, e;
  get_range(n_bits, &b, &e);
  
  return gna() * (e - (b+1)) + (b+1);
}

void gna_i_ranged(integer n, integer b, integer e) {
  real a, er;
  
  inits_r(a, er, NULL);
  gna_i(a);

  sub_i(e, e, b);
  set_r_i(er, e);
  mul_r(a, a, er);
  set_i_r(n, a);
  sum_i(n, n, b);

  clears_r(a, er, NULL);
}

#endif