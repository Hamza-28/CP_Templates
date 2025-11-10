#include <bits/stdc++.h>
using namespace std;

struct Sqrt {
  int block_size;
  vector<int> nums;
  vector<long long> blocks;
  Sqrt(int sqrtn, vector<int> &arr) : block_size(sqrtn), blocks(sqrtn, 0) {
    nums = arr;
    for (int i = 0; i < nums.size(); i++) { blocks[i / block_size] += nums[i]; }
  }

  /** O(1) update to set nums[x] to v */
  void update(int x, int v) {
    blocks[x / block_size] -= nums[x];
    nums[x] = v;
    blocks[x / block_size] += nums[x];
  }

  /** O(sqrt(n)) query for sum of [0, r) */
  long long query(int r) {
    long long res = 0;
    for (int i = 0; i < r / block_size; i++) { res += blocks[i]; }
    for (int i = (r / block_size) * block_size; i < r; i++) { res += nums[i]; }
    return res;
  }

  /** O(sqrt(n)) query for sum of [l, r) */
  long long query(int l, int r) { return query(r) - query(l - 1); }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) { cin >> arr[i]; }
  Sqrt sq((int)ceil(sqrt(n)), arr);

  for (int i = 0; i < q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      sq.update(l - 1, r);
    } else {
      cout << sq.query(l, r) << "\n";
    }
  }
}


#include <bits/stdc++.h>
using namespace std;

struct Query {
  int l, r, idx;
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) { cin >> v[i]; }

  int q;
  cin >> q;
  vector<Query> queries;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    queries.push_back({--x, --y, i});
  }

  int block_size = (int)sqrt(n);
  auto mo_cmp = [&](Query a, Query b) {
    int block_a = a.l / block_size;
    int block_b = b.l / block_size;
    if (block_a == block_b) { return a.r < b.r; }
    return block_a < block_b;
  };
  sort(queries.begin(), queries.end(), mo_cmp);

  int different_values = 0;
  vector<int> values(VALMAX);
  auto remove = [&](int idx) {
    values[v[idx]]--;
    if (values[v[idx]] == 0) { different_values--; }
  };
  auto add = [&](int idx) {
    values[v[idx]]++;
    if (values[v[idx]] == 1) { different_values++; }
  };

  int mo_left = -1;
  int mo_right = -1;
  vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    int left = queries[i].l;
    int right = queries[i].r;

    while (mo_left < left) { remove(mo_left++); }
    while (mo_left > left) { add(--mo_left); }
    while (mo_right < right) { add(++mo_right); }
    while (mo_right > right) { remove(mo_right--); }

    ans[queries[i].idx] = different_values;
  }

  for (int i = 0; i < q; i++) { cout << ans[i] << '\n'; }
}
