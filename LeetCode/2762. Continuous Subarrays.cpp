class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long n = nums.size(), ans = 0, o = 0;

        multiset<int>s;
        for(int i = 0; i < n ;i++){
            s.insert(nums[i]);

            while(*s.rbegin() - *s.begin() > 2)
                 s.erase(s.find(nums[o++]));
        
            ans += i - o + 1;
        }
        return ans;
    }
};

