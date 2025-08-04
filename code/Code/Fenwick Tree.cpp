struct FenwickTree {
  vector<ll> bit;
  ll n;

  FenwickTree(int n) {
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

struct FenwickTree2D {
  vector<vector<int>> bit;
  int n, m;

  FenwickTree2D(int n, int m) {
    this->n = n;
    this->m = m;
    bit.assign(n, vector<int>(m, 0));
  }

  int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
      for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
        ret += bit[i][j];
    return ret;
  }

  void add(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
      for (int j = y; j < m; j = j | (j + 1))
        bit[i][j] += delta;
  }
};
