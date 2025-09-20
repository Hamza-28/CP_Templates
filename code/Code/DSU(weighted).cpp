const int N = 2e5 + 3;
int par[N], sz[N];
long long w[N];

int find(int u) {
  if (par[u] == u) return u;
  int p = find(par[u]);
  w[u] += w[par[u]];
  return par[u] = p;
}

bool unite(int a, int b, ll d) {
  int u = find(a), v = find(b);
  if (u == v) return w[a] - w[b] == d;
  if (sz[u] < sz[v]) {
    w[u] += d + w[b] - w[a];
    par[u] = v;
    sz[v] += sz[u];
  } else {
    w[v] += w[a] - d - w[b];
    par[v] = u;
    sz[u] += sz[v];
  }
  return true;
}

void solve() {
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    sz[i] = 1;
  }

  for (int i = 1; i <= q; ++i) {
    int a, b, d;
    cin >> a >> b >> d;
    if (unite(a, b, d)) cout << i << " ";
  }
  cout << endl;
}
