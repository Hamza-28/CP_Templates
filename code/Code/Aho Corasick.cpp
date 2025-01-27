const int N = 1e6 + 3, A = 26;
int trie[N][A], node[N], dp[N];
int total = 0;
void add(string& s, int i) {
  int u = 0;
  for (char c: s) {
    int k = c - 'a';
    if (!trie[u][k]) {
      trie[u][k] = ++total;
    }
    u = trie[u][k];
  }
  node[i] = u;
}
vector<int> ord;
int slink[N];
void build() {
  queue<int> q; 
  q.push(0);
  while (q.size()) {
    int p = q.front();
    q.pop();
    ord.push_back(p);
    for (int c = 0; c < A; ++c) {
      int u = trie[p][c];
      if (!u) continue;
      q.push(u);
      if (!p) continue;
      int v = slink[p];
      while (v and !trie[v][c]) v = slink[v];
      if (trie[v][c]) slink[u] = trie[v][c];
    }
  }
}
void solve() {
  build();  
  int u = 0;
  for (char c: text) {
    c -= 'a';
    while (u and !trie[u][c]) u = slink[u];
    u = trie[u][c];
    dp[u]++;
  }
  reverse(ord.begin(), ord.end());
  for (int u: ord) {
    dp[slink[u]] += dp[u];
  }
}
