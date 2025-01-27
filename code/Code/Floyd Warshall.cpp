const int N = 100, inf = 1e9 + 9;
int d[N][N], nextof[N][N];
int n;
void init() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      nextof[i][j] = j;
      d[i][j] = inf;
      if (i == j) d[i][j] = 0;
    }
  }
}
void cal() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j]; 
          nextof[i][j] = nextof[i][k];
        }
      }
    }
  }
}
vector<int> findPath(int i, int j) {
  vector<int> path = {i};
  while(i != j) {
    i = nextof[i][j];
    path.push_back(i);
  }
  return path;
}