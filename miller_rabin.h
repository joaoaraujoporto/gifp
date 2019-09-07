#ifndef __miller_rabin_h__
#define __miller_rabin_h__

#include "math.h"
#include "util.h"

bool get_rd(int n, int *r, int *d);
bool is_prime(int n, int k);

/**
 * Factor out powers of 2 from n − 1, being n > 1
 * (for write n as 2^r * d + 1)
 * @param n is a number for factoring
 * @param r is a pointer to the exponent returned
 * @param d is a pointer to the odd returned
 * @return true if result is okay, false otherwise 
 **/
bool get_rd(int n, int *r, int *d) {
  if (n < 2) return false;

  *r = 0;
  *d = n-1;

  while (*d % 2 == 0) {
    *d /= 2;
    *r += 1;
  }

  return true;
}

// bool is_prime(int n, int k) {
//   if (n < 4 || n % 2 == 0) return 0;  

//   int r = 1;
//   int d = 1;
  
//   int i;
//   for (i = 0; i < k; i++) {
//     int a = (int) gna(1) * (n-2) + 2;
//     int x = (int) pow(a, d) % n;

//     if (x == 1 || x == n-1) continue;

//     int k;
//     for (k = 0; k < r-1; k++) {
//       x = (int) pow(x, 2) % n;
//       if (x == n-1) continue;
//     }
    
//     return false;
//   }
  
//   return true;
// }

#endif