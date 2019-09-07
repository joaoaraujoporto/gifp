
int gna(int seed);
int gna(int length, int k);

int gna(int seed) {
  return 1;
}

int gna(length, k) {
  int n = gna(length);
  
  while (!is_prime(n, k))
    n = gna(length);

  return n;
}
