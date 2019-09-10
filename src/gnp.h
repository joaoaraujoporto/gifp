#ifndef __gnp_h__
#define __gnp_h__

#include "gna.h"
#include "miller_rabin.h"

int gnp(int length, int k);

int gnp(int length, int k) {
  int n = gnai(length);
  
  while (!is_prime(n, k))
    n = gnai(length);

  return n;
}

#endif