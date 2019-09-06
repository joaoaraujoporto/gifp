#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int gna(int seed) {
  return 1;
}

int gna(length, k) {
  int n = gna(length);
  
  while (!is_prime(n, k))
    n = gna(length);

  return n;
}


// write n as 2r·d + 1 with d odd (by factoring out powers of 2 from n − 1)

void get_rd(int n, int *r, int *d) {
  *r = 0;
  *d = n-1;

  while (*d % 2 == 0) {
    *d = *d/2;
    *r++;
  }
}
  

int is_prime(int n, int k) {
  if (n < 4 || n % 2 == 0) return 0;  

  int r = 1;
  int d = 1;
  
  int i;
  for (i = 0; i < k; i++) {
    int a = (int) gna(1) * (n-2) + 2;
    int x = (int) pow(a, d) % n;

    if (x == 1 || x == n-1) continue;

    int k;
    for (k = 0; k < r-1; k++) {
      x = (int) pow(x, 2) % n;
      if (x == n-1) continue;
    }
    
    return 0;
  }
  
  return 1;
}

int main(int argc, char **argv) {

  if (argc != 3) return 0;

  int n = atoi(argv[1]);
  int k = atoi(argv[2]);
  
  printf("%i\n", is_prime(n, k));

}
