#include <bits/stdc++.h>
using namespace std;

string to_string(const char c) {
  return "'" + string(1, c) + "'";
}

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <size_t N>
string to_string(bitset<N> v) {
  return v.to_string();
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void dbg_out() { cerr << endl; }

template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  dbg_out(T...);
}

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)


// Use Case
// #include "dbg.h"
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   char c = 'a';
//   int a = 2;
//   string s = "diu";
//   vector<int> v = {2, 1, 3};
//   set<int> st = {2, 1, 3};
//   map<int, int> cnt;
//   cnt[0]++, cnt[1]++, cnt[0]++;
//   dbg(c, a, s, v, st, cnt);
//   dbg('c');
//   dbg("diu");
//   bitset<5> bs = 5;
//   dbg(bs);
//   dbg(int(bs[2]));
// }
