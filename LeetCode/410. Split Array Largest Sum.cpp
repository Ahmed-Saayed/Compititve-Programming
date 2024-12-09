class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()), r = 1e9;
        
        while(l <= r){
            int m = l + r >> 1, sm = 0, c = 1;
            
            for(auto i : nums){
                sm += i;
                
                if(sm > m)sm = i, c++;
            }

            (c > k ? l = m + 1 : r = m - 1);
        }
        return l;
    }
};