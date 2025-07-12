struct interval_set {
  set<array<ll, 2>> st;
  ll cnt = 0, d = 0;

  void init(ll _d) {
    d = _d;
  }

  void add(ll l, ll r, ll x) {
    cnt += x * (1 + (r - l) / d);
  }

  void insert(ll l, ll r) {
    auto it = st.lower_bound({l, INF});
    if (it != st.begin()) {
      it--;
      if (l <= (*it)[1]) {
        l = (*it)[0];
        r = max(r, (*it)[1]);
        add((*it)[0], (*it)[1], -1);
        st.erase(it);
      }
    }
    while (1) {
      auto it = st.lower_bound({l, -INF});
      if (it == st.end() || r < (*it)[0]) break;
      r = max(r, (*it)[1]);
      add((*it)[0], (*it)[1], -1);
      st.erase(it);
    }
    add(l, r, 1);
    st.insert({l, r});
  }

  ll count() {
    return cnt;
  }
};
