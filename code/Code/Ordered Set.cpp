/**
*Description: *x.find\_by\_order(k) : iterator to the k-th index\\
               x.order\_of\_key(k) : number of items smaller than k
 */
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;