const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319; // 911382323, 972663749
const int N = 1e6 + 3;
array<int, 2> pref[N], rev[N];
int pw1[N], pw2[N], ipw1[N], ipw2[N];
int power(int a, int n, int mod) {
  int ans = 1 % mod;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}
void prec() {
  pw1[0] = pw2[0] = ipw1[0] = ipw2[0] = 1;
  int ip1 = power(p1, mod1 - 2, mod1);
  int ip2 = power(p2, mod2 - 2, mod2);
  for (int i = 1; i < N; ++i) {
    pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
    pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    ipw1[i] = 1LL * ipw1[i - 1] * ip1 % mod1;
    ipw2[i] = 1LL * ipw2[i - 1] * ip2 % mod2;
  }
}
void build(string& s) {
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    pref[i][0] = 1LL * s[i] * pw1[i] % mod1;
    if (i) pref[i][0] = (pref[i][0] + pref[i - 1][0]) % mod1;
    pref[i][1] = 1LL * s[i] * pw2[i] % mod2;
    if (i) pref[i][1] = (pref[i][1] + pref[i - 1][1]) % mod2;

    rev[i][0] = 1LL * s[i] * ipw1[i] % mod1;
    if (i) rev[i][0] = (rev[i][0] + rev[i - 1][0]) % mod1;
    rev[i][1] = 1LL * s[i] * ipw2[i] % mod2;
    if (i) rev[i][1] = (rev[i][1] + rev[i - 1][1]) % mod2;
  }
}
array<int, 2> get_hash(int i, int j) {
  array<int, 2> ans = {0, 0};
  ans[0] = pref[j][0];
  if (i) ans[0] = (pref[j][0] - pref[i - 1][0] + mod1) % mod1;
  ans[1] = pref[j][1];
  if (i) ans[1] = (pref[j][1] - pref[i - 1][1] + mod2) % mod2;
  ans[0] = 1LL * ans[0] * ipw1[i] % mod1;
  ans[1] = 1LL * ans[1] * ipw2[i] % mod2;
  return ans;
}
array<int, 2> get_rev_hash(int i, int j) {
  array<int, 2> ans = {0, 0};
  ans[0] = rev[j][0];
  if (i) ans[0] = (rev[j][0] - rev[i - 1][0] + mod1) % mod1;
  ans[1] = rev[j][1];
  if (i) ans[1] = (rev[j][1] - rev[i - 1][1] + mod2) % mod2;
  ans[0] = 1LL * ans[0] * pw1[j] % mod1;
  ans[1] = 1LL * ans[1] * pw2[j] % mod2;
  return ans;
}