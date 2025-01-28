struct _2SAT {
	int N;
	vector<bool> vis, value;
	vector<int> order, comp;
	vector<vector<int>> adj, adjT;

	_2SAT(int n) : N(n), adj(2 * n), adjT(2 * n), vis(2 * n), comp(2 * n), value(2 * n) {}  

	void dfs1(int u) {
		vis[u] = true;
		for (auto v: adj[u]) {
			if (!vis[v]) {
				dfs1(v);
			}
		}
		order.push_back(u);
	}

	void dfs2(int u, int cnt) {
		comp[u] = cnt;
		for (auto v: adjT[u]) {
			if (!comp[v]) {
				dfs2(v, cnt);
			}
		}
	}

	void Kosaraju() {
		for (int i = 0; i < 2 * N; ++i) {
			if (!vis[i]) dfs1(i);
		}
		reverse(order.begin(), order.end());

		int cnt = 1;
		for (auto u: order) {
			if (!comp[u]) {
				dfs2(u, cnt++);
			}
		}
	}

	bool assignment() {
		for (int i = 0; i < N; ++i) {
			if (comp[i] == comp[i + N]) {
				return false;
			}	
			value[i] = comp[i] < comp[i + N] ? 0 : 1;
		}
		return true;
	}

	void addDisjunction(int a, bool pos_a, int b, bool pos_b) { // a V b
		int neg_a = a + N, neg_b = b + N;

		if (!pos_a) swap(a, neg_a);
		if (!pos_b) swap(b, neg_b);

		adj[neg_a].push_back(b);
		adj[neg_b].push_back(a);

		adjT[a].push_back(neg_b);
		adjT[b].push_back(neg_a);
	}
};
