istream& operator >>(istream& cin, __int128& x) {
  string s;
  cin >> s;
  x = 0;
  for (int i = 0; i < s.size(); ++i) {
    x = x * 10 + (s[i] - '0');
  }
  return cin;
}
ostream& operator <<(ostream& cout, __int128 x) {
  if (x == 0) {
    cout << 0;
    return cout;
  }
  if (x < 0) {
    cout << "-";
    x *= -1;
  }
  string s;
  while (x) {
    s += (x % 10) + '0';
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
  return cout;
}
