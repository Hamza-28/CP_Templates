vector<ll> fact(21, 1);
//does not handle if given ff-th permutation does not exist
string n_th_Permutation(string s, ll ff){
	int n = s.size();
	for(int i=0; i<n; i++){
		sort(s.begin()+i, s.end());
		int pos = i+ff/fact[n-1-i];
		ff %= fact[n-1-i];
		swap(s[i], s[pos]);
	}
	return s;
}