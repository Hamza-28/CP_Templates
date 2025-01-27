const int N = 1e6 + 3;
int nextof[N][26], cnt[N];
int tot = 1;
void add(string& s) {
  int u = 1;
  ++cnt[u];
  for (auto c: s) {
    int v = c - 'a';
    if (!nextof[u][v]) {
      nextof[u][v] = ++tot;  
    }
    u = nextof[u][v];
    ++cnt[u];
  }
}
int countPref(string& s) {
  int u = 1;
  for (auto c: s) {
    int v = c - 'a';
    if (!nextof[u][v]) return 0;
    u = nextof[u][v];
  }
  return cnt[u];
}