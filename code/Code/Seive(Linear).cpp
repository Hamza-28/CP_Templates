const int N = 10000000;
vector<int> spf(N+1);
vector<int> pr;

for (int i=2; i <= N; ++i) {
    if (spf[i] == 0) {
        spf[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        spf[i * pr[j]] = pr[j];
        if (pr[j] == spf[i]) {
            break;
        }
    }
}
