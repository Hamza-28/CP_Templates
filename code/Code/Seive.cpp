const int N = 1e6 + 3;
bitset<N> isPrime;
vector<int> prime;
void seive() {
  isPrime[2] = 1;
  for (int i = 3; i <= N; i+=2) {
    isPrime[i] = 1;
  }
  for (int i = 3; i * i <= N; i += 2) {
    if(isPrime[i]) {
      for (int j = i * i; j <= N; j += (i + i)) {
        isPrime[j] = 0;
      }
    }
  }
  prime.push_back(2);
  for (int i = 3; i <= N; i+=2) {
    if(isPrime[i]) {
      prime.push_back(i);
    }
  }
}