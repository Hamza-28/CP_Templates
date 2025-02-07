const int N = 10000000;
vector<int> spf(N+1);
vector<int> primes;

for (int i=2; i <= N; ++i) {
    if (spf[i] == 0) {
        spf[i] = i;
        primes.push_back(i);
    }
    for (int j = 0; i * primes[j] <= N; ++j) {
        spf[i * primes[j]] = primes[j];
        if (primes[j] == spf[i]) {
            break;
        }
    }
}
