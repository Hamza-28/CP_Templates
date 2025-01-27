const int N = 2e5 + 3, M = __bit_width(N) + 1;
int maxTable[N][M], a[N];
void buildTable(int n) {
	for (int i = 0; i < n; ++i) {
		maxTable[i][0] = a[i];
	}
	for (int k = 1; k < M; ++k) {
		for (int i = 0; i + (1 << k) <= n; ++i) {
			maxTable[i][k] = max(maxTable[i][k - 1], maxTable[i + (1 << (k - 1))][k - 1]);
		}
	}
}
int maxQuery(int i, int j, int n) {
	if (j < 0 or i >= n) return INT32_MIN;
	int k = __bit_width(j - i + 1) - 1;
	return max(maxTable[i][k], maxTable[j - (1 << k) + 1][k]);
}