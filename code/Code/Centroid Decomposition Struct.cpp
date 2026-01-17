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
