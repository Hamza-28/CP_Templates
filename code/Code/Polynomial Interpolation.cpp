// P(x) = a0 + a1x + a2x^2 + ... + anx^n
// y[i] = P(i)
int inv(ll a) {
   a = (a + mod) % mod;
   return power(a, -1);
}
ll eval (vector<ll> y, ll k) {
  int n = y.size() - 1;
  if (k <= n) {
    return y[k];
  }
  vector<ll> L(n + 1, 1);
  for (int x = 1; x <= n; ++x) {
    L[0] = L[0] * (k - x) % mod;
    L[0] = L[0] * inv(-x) % mod;
  }
  for (int x = 1; x <= n; ++x) {
    L[x] = L[x - 1] * inv(k - x) % mod * (k - (x - 1)) % mod;
    L[x] = L[x] * ((x - 1) - n + mod) % mod * inv(x) % mod;
  }
  ll yk = 0;
  for (int x = 0; x <= n; ++x) {
    yk = (yk + L[x] * y[x] % mod) % mod;
  }
  return yk;
}