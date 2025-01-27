// Articulation point
vector<vector<int>> adj;
vector<int> tin, low;
vector<bool> vis;
int timer;
void is_cutpoint(int v) {
	// process the cutpoint
}
void dfs(int v, int p = -1) {
	vis[v] = true;
	tin[v] = low[v] = timer++;
	int children = 0;
	for (int u : adj[v]) {
		if (u == p) continue;
		if (vis[u]) {
			low[v] = min(low[v], tin[u]);
		} else {
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if (low[u] >= tin[v] && p != -1) {
				is_cutpoint[v] = true;
			}
			++children;
		}
	}
	if(p == -1 && children > 1) {
		is_cutpoint[v] = true;
	}
}
void find_cutpoints(int n) {
	timer = 0;
	vis.assign(n + 1, false);
	is_cutpoint.assign(n + 1, false);
	tin.assign(n + 1, -1);
	low.assign(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs (i);
		}
	}
}

// Bridges
vector<vector<int>> adj;
vector<int> tin, low;
vector<bool> vis;
int timer;
void is_bridge(int v,int to) {
	//process the found bridge
}
void dfs(int v, int p = -1) {
	vis[v] = true;
	tin[v] = low[v] = timer++;
	bool parent_skipped = false;
	for (int u : adj[v]) {
		if (u == p && !parent_skipped) {
			parent_skipped = true;
			continue;
		}
		if (vis[u]) {
			low[v] = min(low[v], tin[u]);
		} else {
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if (low[u] > tin[v]) {
				is_bridge(v, u);
			}
		}
	}
}
void find_bridges() {
	timer = 0;
	vis.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}