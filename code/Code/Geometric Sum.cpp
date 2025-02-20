ll geometric_Sum() {
	ll a, r, n; cin >> a >> r >> n; //a = first value r = ratio, n = n-term
	ll res = BigMod(r, n);
	ll numara = (a * (1 - res)) % MOD;
	numara = (numara + MOD) % MOD;
	ll deno = ((1 - r) % MOD + MOD) % MOD;
	ll ans = (numara * BigMod(deno, MOD - 2)) % MOD;
	return ans;
}
// geometric sum for any MOD
const int mod = 1e9 + 7;
	int geo_all(int n, int x) { //1 + x + x^2 + x^3 ....x^n = f(n, x)
	if (n == 0) return 0;
	int ret = 1ll * (1 + x) * geo_all(n / 2, 1ll * x * x % mod) % mod;
	if (n & 1) ret = (1 + 1ll * x * ret) % mod;
	return ret;
}
