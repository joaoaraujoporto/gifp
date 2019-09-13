#ifndef __gnp_h__
#define __gnp_h__

#include "gna.h"
#include "miller_rabin.h"

ul_int gnp(u_int n_bits, int k);

ul_int gnp(u_int n_bits, int k) {
  if (n_bits < 3) return 0;

  ul_int n = gnab(n_bits);
  
  while (!is_prime(n, k))
    n = gnab(n_bits);

  return n;
}

#endif