#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_multiset <ll> os;
        int n=nums.size(),ans=0;

        for(int i=n-1;~i;i--){
            ans+=os.order_of_key (nums[i]);
            os.insert(nums[i]*2ll);
        }

        return ans;
    }
};
