class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<int>s;
        for(int i = 0 ; i < nums.size() ;i++){
            s.insert(nums[i]);

            if(i - k + 1 >= 0){
                ans.push_back(* s.rbegin() );
                s.erase( s.find(nums[i - k + 1]));
            }
        }

        return ans;
    }
};