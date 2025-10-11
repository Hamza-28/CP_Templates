const int N = 1e5 + 9;

int vis[N], id[N];
vector<int> adj[N], adj_t[N];
vector<int> order;

void dfs1(int v) {
	vis[v] = 1;
	for (int u: adj[v]) {
		if (!vis[u]) {
			dfs1(u);
		}
	}
	order.push_back(v);
}
void dfs2(int v, int cnt) {
	id[v] = cnt;
	for (int u: adj_t[v]) {
		if (!id[u]) {
			dfs2(u, cnt);
		}
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_t[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	reverse(order.begin(), order.end());
	int cnt = 1;
	for (auto v: order) {
		if (!id[v]) {
			dfs2(v, cnt++);
		}
	}
}
