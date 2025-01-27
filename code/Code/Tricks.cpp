//Maximum Subarray Sum (Kadane's algo)
ll max_so_far = -inf, max_end_here = 0;
for (ll i = 1; i <= n; i++) {
    max_end_here += a[i];
    if (max_end_here > max_so_far) max_so_far = max_end_here;
    if (max_end_here < 0) max_end_here = 0;
}
return max_so_far;

// Maximum Subarray Size Thats Sum = K
ll n, k; cin >> n >> k;
ll total_sum = 0;
vector < ll > pre(n + 7, 0);
for (ll i = 1; i <= n; i++) {
	ll temp; cin >> temp;
	total_sum += temp;
	if (i == 1) pre[i] = temp;
	else pre[i] = pre[i - 1] + temp;
}
if (total_sum < k) { cout << "-1" << endl; return; }
if (total_sum == k) { cout << "0" << endl; return; }
ll maximum_subSize = 0;
gp_hash_table < ll, ll, customHash> table;
for (ll i = 1; i <= n; i++) {
	if (pre[i] >= k) {
		ll subSUM = pre[i] - k;
		if (subSUM == 0) maximum_subSize = max(maximum_subSize, i);
		else if (table[subSUM]) {
			ll left = table[subSUM];
			ll right = i;
			ll subSize = right - left;
			maximum_subSize = max(subSize, maximum_subSize);
    }
  }
	if (!table[pre[i]]) table[pre[i]] = i;
}
cout << maximum_subSize << endl;

// Number of Subarray Sum Equal to K
ll n, k; cin >> n >> k;
ll total_sum = 0;
vector < ll > pre(n + 7, 0);
for (ll i = 1; i <= n; i++) {
	ll temp; cin >> temp;
	total_sum += temp;
	if (i == 1) pre[i] = temp;
	else pre[i] = pre[i - 1] + temp;
}
ll cnt_subarry = 0;
gp_hash_table < ll, ll, customHash> table;
table[0] = 1;
for (ll i = 1; i <= n; i++) {
	cnt_subarry += table[pre[i] - k];
	table[pre[i]]++;
}
cout << cnt_subarry << endl;

// How Many Pairs Of The Array Have GCD g, For All 1<=g<=n
/*a[i] <= 1e6
for all 1<=g<=n, how many pairs exist such that g = gcd(a[i], a[j]);
complexity : nlogn
*/
ll n; cin >> n;
ll a[n + 1];
ll cnt[n + 1]; memset(cnt, 0, sizeof cnt);
for (ll i = 1; i <= n; i++) {cin >> a[i]; cnt[a[i]]++;}
ll gcd[n + 1]; memset(gcd, 0, sizeof gcd);
for (ll i = n; i >= 1; i--) {
	ll pair = 0, invalid_pair = 0;
	for (ll j = i; j <= n; j += i) {
		pair += cnt[j];
		invalid_pair += gcd[j];
  }
	pair = (pair * (pair - 1)) / 2;
	gcd[i] = pair - invalid_pair;
	// how many pairs exist whose gcd is i 
}
