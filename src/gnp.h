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

ul_int gnp2(u_int n_bits, int k) {
  if (n_bits < 3) return 0;

  ul_int n = gnab(n_bits);
  
  ul_int i, b, e;
  get_range(n_bits, &b, &e);
  ul_int limit = (e - b)/2 + 1; // simplified

  for (i = 0; !is_prime(n, k) && i < limit; i++)
    n = gnab(n_bits);

  if (i == limit) return 0;
  return n;
}

ul_int gnp3(u_int n_bits, int k) {
  if (n_bits < 3) return 0;

  ul_int n = gnab(n_bits);
  
  ul_int i, b, e;
  get_range(n_bits, &b, &e);
  ul_int limit = (e - b); // simplified.
  // printf("n == %ld\n", n);
  // printf("limit == %ld\n", limit);
  ul_int vis[limit];

  for (i = 0; i < limit; i++) {
    // if (n == 40961) printf("n == %ld\n", n);
    while (contains(n, vis, i)) n = gnab(n_bits);
    // if (n == 40961) printf("n == %ld\n", n);
    if (is_prime(n, k)) break;
    vis[i] = n;

    // if (n == 40961)
    //   printf("n == %ld\n", n);

  }

  // // if (n == 40961) printf("n == %ld\n", n);
  // if (contains(40961, vis, i)) printf("n == %ld\n", n);
  // printf("i == %ld\n", i);
  if (i == limit) return 0;
  return n;
}

#endif