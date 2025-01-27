#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct custom_hash {
	int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, custom_hash> mp;
