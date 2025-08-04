struct FenwickTree {
  vector<ll> bit;
  ll n;

  FenwickTree(ll n) {
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vector<ll> const &a) : FenwickTree(a.size()){
    for (int i = 0; i < n; i++) {
      bit[i] += a[i];
      int r = i | (i + 1);
      if (r < n) bit[r] += bit[i];
    }
  }

  ll sum(int r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, ll delta) {
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};
