#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
#define all(v) (v).begin(),(v).end()

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans;
        ordered_multiset <int> os;

        for(int i = nums.size() - 1; ~i; i--){
            os.insert(nums[i]),
            ans.push_back(os.order_of_key (nums[i]));
        }
        reverse(all(ans));

        return ans;
    }
};