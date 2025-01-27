const int N = 1E6 + 5;
int mu[N];
void pre() {
  mu[1] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = i + i; j < N; j += i) {
      mu[j] -= mu[i];
    }
  }
}