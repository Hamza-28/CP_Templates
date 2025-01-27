struct custom_compare {
  bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
    // Compare in decreasing order of the first element
    if (get<0>(a) != get<0>(b)) {
      return get<0>(a) > get<0>(b);
    }
    // If the first element is equal, compare in increasing order of the second element
    if (get<1>(a) != get<1>(b))
      return get<1>(a) < get<1>(b);
    return get<2>(a) < get<2>(b);
  }
};
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using indexed_set = tree<T, null_type, custom_compare, rb_tree_tag, tree_order_statistics_node_update>;
