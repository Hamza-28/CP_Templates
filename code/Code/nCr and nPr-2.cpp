const int N = 2005, mod = 1e9 + 7;
int C[N][N], fact[N];
void prec() { // O(n^2)
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
  }
}
int nCr(int n, int r) { // O(1)
  if (n < r) return 0;
  return C[n][r];
}
int nPr(int n, int r) { // O(1)
  if (n < r) return 0;
  return 1LL * nCr(n, r) * fact[r] % mod;
}