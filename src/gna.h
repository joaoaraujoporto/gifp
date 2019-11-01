#ifndef __gna_h__
#define __gna_h__

#include "../src/util.h"
#include "time.h"
#include "math.h"

ul_int seed = 0;
char* seed_s; // TODO - memory leak? Yep.

double gna();
double sgna(int nseed);
ul_int gnai(int n_digits);
ul_int gnab(u_int n_bits);

void gna_i(real n);
void sgna_i(real n, const integer nseed_i);
void gna_i_ranged(integer n, const integer b, const integer e);
void gnab_i(integer n, ul_int n_bits);


/**
 * Generates a pseudo-random double in the range [0,1].
 * If a seed wasn't never defined with sgna(), set the seed
 * with currently time.
 * @return the pseudo-random number
 */
double gna() {
  ul_int multiplier, modulo;

  if (seed == 0) seed = time(NULL);

  multiplier = 46341;
  modulo = 2147483647;
  seed = seed * multiplier % modulo;
  
  return (double) seed / (double) modulo;
}

/**
 * Generates a pseudo-random double in the range [0,1] based on a seed.
 * @param nseed is the seed
 * @return the pseudo-random number
 */
double sgna(int nseed) {
  seed = nseed;
  return gna();
}

/** Generates a pseudo-random unsigned long int
 * with a given number of digits.
 * @param n_digits is the number of digits
 * @return the pseudo-random number or 0 if n_bits < 0
 */
ul_int gnai(int n_digits) {
  if (n_digits < 1) return 0;

  ul_int n, c;
  u_int r, q;

  n = 0; c = 0;
  r = n_digits%6;
  q = n_digits/6;

  int i;
  for (i = 0; i < q; i++) {
    u_int p = (u_int) (gna() * 1e6);
    while (p == 0 || p < 1e5) p = (u_int) (gna() * 1e6);
    n += (ul_int) (p * pow(10, 6*i));
  }

  int j;
  for (int j = 0; j < r; j++) {
    u_int p = (u_int) (gna() * 1e1);
    while (p == 0) p = (u_int) (gna() * 1e1);
    c += (ul_int) (p * pow(10, j));
  }

  n += (ul_int) (c * pow(10, 6*i));
  return n;
}

/** Generates a pseudo-random unsigned long int
 * with a given number of bits.
 * @param n_bits is the number of bits
 * @return the pseudo-random number or 0 if n_bits < 0
 */
ul_int gnab(u_int n_bits) {
  if (n_bits < 1) return 0;

  ul_int b, e;
  get_range(n_bits, &b, &e);
  
  return gna() * (e - (b+1)) + (b+1);
}

/**
 * Generates a pseudo-random real in the range [0,1].
 * If a seed wasn't never defined with sgna_i(), set the seed
 * with currently time.
 * @return the pseudo-random number
 * @param n is a pointer to the real where will be stored the pseudo-random real
 */
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

/**
 * Generates a pseudo-random real in the range [0,1] based on a seed.
 * @param nseed is the seed
 * @param n is a pointer to the real where will be stored the pseudo-random real
 */
void sgna_i(real n, const integer nseed_i) {
  seed_s = get_i_s(NULL, 10, nseed_i);
  gna_i(n);
}

/**
 * Generates a pseudo-random integer in a given range [b,e].
 * If a seed wasn't never defined with sgna_i(), set the seed
 * with currently time.
 * @param b is the begin of the range
 * @param e is the end of the range
 * @param n is a pointer to the integer where will be stored the pseudo-random integer
 */
void gna_i_ranged(integer n, const integer b, const integer e) {
  real a, er;
  
  inits_r(a, er, NULL);
  gna_i(a);

  sub_i(n, e, b);
  set_r_i(er, n);
  mul_r(a, a, er);
  set_i_r(n, a);
  sum_i(n, n, b);

  clears_r(a, er, NULL);
}

/** Generates a pseudo-random integer
 * with a given number of bits.
 * @param n_bits is the number of bits
 * @param n is a pointer to the integer where will be stored the pseudo-random integer
 */
void gnab_i(integer n, ul_int n_bits) {
  integer b, e;
  inits_i(b, e, NULL);

  get_range_i(n_bits, b, e);
  gna_i_ranged(n, b, e);

  clears_i(b, e, NULL);
}

#endif