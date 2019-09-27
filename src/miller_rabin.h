#ifndef __miller_rabin_h__
#define __miller_rabin_h__

#include "math.h"
#include "util.h"
#include "gna.h"

bool get_rd(ul_int n, ul_int *r, ul_int *d);
bool is_prime(ul_int n, ul_int k);

/**
 * Factor out powers of 2 from n − 1, being n > 1
 * (for write n as 2^r * d + 1)
 * @param n is a number for factoring
 * @param r is a pointer to the exponent returned
 * @param d is a pointer to the odd returned
 * @return true if result is okay, false otherwise 
 */
bool get_rd(ul_int n, ul_int *r, ul_int *d) {
  if (n < 2) return false;

  *r = 0;
  *d = n-1;

  while (*d % 2 == 0) {
    *d /= 2;
    *r += 1;
  }

  return true;
}

bool get_rd_i(const integer n, integer r, integer d) {
  if (cmp_i_ui(n, 1) < 1) return false;

  integer rm; init_i(rm);
  set_i_ui(r, 0);
  sub_i_ui(d, n, 1);

  mod_i_ui(rm, d, 2);
  while (!cmp_i_ui(rm, 0)) {
    div_i_ui(d, d, 2);
    sum_i_ui(r, r, 1);
    mod_i_ui(rm, d, 2);
  }

  return true;
}

/**
 * Test if a number is prime
 * @param n is the number for test, n > 3
 * @param k is the number of iterations
 * @return true if probably prime, false otherwise
 */
bool is_prime(ul_int n, ul_int k) {
  if (n < 4 || n % 2 == 0) return false;

  ul_int r, d;
  get_rd(n, &r, &d);
  // printf("n == %ld\n", n);
  // printf("r == %ld, d == %ld\n", r, d);
  
  int i;
  for (i = 0; i < k; i++) {
    u_int a = (u_int) (gna() * (n-4)) + 2;
    u_int x = (u_int) pow(a, d) % n;

    // printf("a == %d, x == %d\n", a, x);

    if (x == 1 || x == n-1) continue;

    int j;
    for (j = 0; j < r-1; j++) {
      x = (u_int) pow(x, 2) % n;
      // printf("x == %d\n", x);
      if (x == n-1) break;
    }

    if (j == r-1) return false;
  }
  
  return true;
}

bool is_prime_i(const integer n, ul_int k) {
  if (cmp_i_ui(n, 3) < 1 || divs_i_ui(n, 2)) return false;

  integer r, d, a, x, aux, aux2, aux3;
  inits_i(r, d, a, x, aux, aux2, aux3, NULL);

  get_rd_i(n, r, d);

  // gmp_printf("n == %Zd, r == %Zd, d == %Zd\n", n, r, d);
  
  int i;
  for (i = 0; i < k; i++) {
    integer a, x, aux, aux2, aux3;
    inits_i(a, x, aux, aux2, aux3, NULL);

    set_i_ui(aux, 2);
    sub_i_ui(aux2, n, 2);
    gna_i_ranged(a, aux, aux2);
    powm_i(x, a, d, n);

    // gmp_printf("a == %Zd, x == %Zd\n", a, x);

    sub_i_ui(aux, n, 1);
    if (!cmp_i_ui(x, 1) || !cmp_i(x, aux)) continue;

    set_i_ui(aux, 0);
    sub_i_ui(aux2, r, 1);
    for ( ; cmp_i(aux, aux2) < 0; sum_i_ui(aux, aux, 1)) {
      set_i_ui(aux3, 2);
      powm_i(x, x, aux3, n);
      // gmp_printf("x == %Zd\n", x);
      sub_i_ui(aux3, n, 1);
      if (!cmp_i(x, aux3)) break;
    }

    if (!cmp_i(aux, aux2)) {
      clears_i(r, d, a, x, aux, aux2, aux3, NULL);
      return false;
    }
  }
  
  clears_i(r, d, a, x, aux, aux2, aux3, NULL);
  return true;
}

#endif