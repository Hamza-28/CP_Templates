struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
	  x += 0x9e3779b97f4a7c15;
	  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	  return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
	  static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
	  return splitmix64(x + FIXED_RANDOM);
 	}
};
unordered_map<long long int, int, custom_hash> mp; // this will work when the key is an int or long long int

// hash pair
struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		 custom_hash hasher; // Create an instance of custom_hash
		 size_t hash1 = hasher(p.first);  
		 size_t hash2 = hasher(p.second); 

		 // Combine hashes
		 if (hash1 != hash2) {
			  return hash1 ^ (hash2 << 1); // Better mixing
		 }
		 return hash1;
	}
};
