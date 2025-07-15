int fact[N], ifact[N];
void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = power(fact[N - 1], -1);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
  }
}
int nPr(int n, int r) {
  if (n < r) return 0;
  return 1LL * fact[n] * ifact[n - r] % mod;
}
int nCr(int n, int r) {
  if (n < r) return 0;
  return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
