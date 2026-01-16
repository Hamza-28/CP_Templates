const int N = 2e5+5;
int n, k;
vector<int> adj[N];
int sz[N], cen[N];
ll ans = 0;
void dfs_sz(int u, int p) {
  sz[u] = 1;
  for (auto v: adj[u]) {
    if (v != p and !cen[v]) {
      dfs_sz(v, u);
      sz[u] += sz[v];
    }
  }
}
int get_cen(int u, int p, int s) {
  for (auto v: adj[u]) {
    if (v != p and !cen[v] and 2 * sz[v] > s)  return get_cen(v, u, s);
  }
  return u;
}
int t, tin[N], tout[N], nodes[N], dep[N];
void dfs(int u, int p) {
  nodes[t] = u;
  tin[u] = t++;
  for (auto v: adj[u]) {
    if (v != p and !cen[v]) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
  tout[u] = t - 1;
}
void go(int u) {
  dfs_sz(u, u);
  int c = get_cen(u, u, sz[u]);
  cen[c] = 1;
  t = 0;
  dep[c] = 0;
  dfs(c, c);
  int cnt[t]{1};
  for (auto v: adj[c]) {
    if (!cen[v]) {
      for (int i = tin[v]; i <= tout[v]; ++i) {
        int w = nodes[i];
        int req = k - dep[w];
        if (req >= 0 and req < t) {
          ans += cnt[req];
        }
      }
      for (int i = tin[v]; i <= tout[v]; ++i) {
        int w = nodes[i];
        cnt[dep[w]]++;
      }
    }
  }
  for (auto v: adj[c]) {
    if (!cen[v]) {
      go(v);
    }
  }
}
void solve () {
  cin >> n >> k;
  for (int e = 0; e < n - 1; ++e) {
    int u, v;  cin >> u >> v;  u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  go(0);
  cout << ans << "\n";
}

// 
struct CentroidDecomposition {
  set<int> adj[N];
  map<int, int> dis[N];
  int sz[N], par[N], ans[N];

  void init(int n) {
    for(int i = 1 ; i <= n ; ++i) {
			adj[i].clear(), dis[i].clear();
			ans[i] = inf;
		}
  }
  void addEdge(int u, int v) {
    adj[u].insert(v); adj[v].insert(u);
  }
  int dfs(int u, int p) {
    sz[u] = 1;
    for(auto v : adj[u]) if(v != p) {
      sz[u] += dfs(v, u);
    }
    return sz[u];
  }
  int centroid(int u, int p, int n) {
    for(auto v : adj[u]) if(v != p) {
      if(sz[v] > n / 2) return centroid(v, u, n);
    }
    return u;
  }
  void dfs2(int u, int p, int c, int d) { 
    dis[c][u] = d;
    for(auto v : adj[u]) if(v != p) {
      dfs2(v, u, c, d + 1);
    }
  }
  void build(int u, int p) {
    int n = dfs(u, p);
    int c = centroid(u, p, n);
    if(p == -1) p = c;
    par[c] = p;
    dfs2(c, p, c, 0);

    vector<int> tmp(adj[c].begin(), adj[c].end());
    for(auto v : tmp) {
      adj[c].erase(v); adj[v].erase(c);
      build(v, c);
    }
  }
  void modify(int u) {
    for(int v = u ; v != 0 ; v = par[v]) {
			ans[v] = min(ans[v], dis[v][u]);
		}
  }
  int query(int u) {
    int mn = inf;
    for(int v = u ; v != 0 ; v = par[v]) {
			mn = min(mn, ans[v] + dis[v][u]);
		}
    return mn;
  }
} cd;
