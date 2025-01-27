const int mod = 1e9 + 7;
struct Mat { 
  int sz;
  vector<vector<int>> val;
  Mat(int sz) {
    this->sz = sz;
    val.resize(sz, vector<int>(sz, 0));
  }
  Mat(int sz, int v) {
    this->sz = sz;
    val.resize(sz, vector<int>(sz, 0));
    for (int i = 0; i < sz; ++i) {
      val[i][i] = v; // diagonal values
    }
  }
  Mat operator * (Mat m2) {
    Mat ans(sz);
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        for (int k = 0; k < sz; ++k) {
          ans.val[i][j] = (ans.val[i][j] + (1LL * val[i][k] * m2.val[k][j]) % mod) % mod;
        }
      }
    }
    return ans;
  } 
};
Mat Mat_Expo(Mat a, long long n) {
  Mat ans(a.sz, 1);  // identity matrix
  while (n) {
    if (n & 1) {
      ans = ans * a;
    }
    a = a * a;
    n >>= 1;
  }
  return ans;
}