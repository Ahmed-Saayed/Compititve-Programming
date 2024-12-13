class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xo=0;
        for(auto i:nums)xo^=i;

        return !xo||nums.size()%2==0;
    }
};