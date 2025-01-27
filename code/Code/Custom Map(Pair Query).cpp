// a1 <= a2 <= a3 <= a4......
// b1 >= b2 >= b3 >= b4......
map<ll, ll> mp;
void insert(ll a, ll b) {
  auto it = mp.lower_bound(a);
  if (it != mp.end() and it->second >= b) return;
  it = mp.insert(it, {a, b});
  it->second = b;
  while (it != mp.begin() and prev(it)->second <= b) {
    mp.erase(prev(it));
  }
}
// returns the largest b among the a's that are greater than or equal to x
ll query(ll x) {
  auto it = mp.lower_bound(x);
  if (it == mp.end()) return 0;
  return it->second;
}