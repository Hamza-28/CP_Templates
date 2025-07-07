struct Mint {
  int v;
  Mint(long long val = 0) {
    v = int(val % MOD);
    if (v < 0) v += MOD;
  }
  Mint operator+(const Mint &o) const { return Mint(v + o.v); }
  Mint operator-(const Mint &o) const { return Mint(v - o.v); }
  Mint operator*(const Mint &o) const { return Mint(1LL * v * o.v); }
  Mint operator/(const Mint &o) const { return *this * o.inv(); }
  Mint& operator+=(const Mint &o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
  Mint& operator-=(const Mint &o) { v -= o.v; if (v < 0) v += MOD; return *this; }
  Mint& operator*=(const Mint &o) { v = int(1LL * v * o.v % MOD); return *this; }
  Mint pow(long long p) const {
    Mint a = *this, res = 1;
    while (p > 0) {
      if (p & 1) res *= a;
      a *= a;
      p >>= 1;
    }
    return res;
  }
  Mint inv() const { return pow(MOD - 2); }
  friend ostream& operator<<(ostream& os, const Mint& m) {
    os << m.v;
    return os;
  }
};
