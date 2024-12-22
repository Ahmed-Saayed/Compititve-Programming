long long dp[300][300][64], mod = 1e9 + 7;
long long rec(int i, int j, int xo, vector<vector<int>>&nums, int k){
    if(i == nums.size() || j == nums[0].size())
        return 0;

    if(i == nums.size() - 1 && j == nums[0].size() - 1)
        return (xo ^ nums[i][j]) == k;

    long long & ret=dp[i][j][xo];
    if(~ret)return ret;

    xo ^= nums[i][j];
    return ret = (rec(i + 1, j, xo,nums ,k) + rec(i,j+1,xo, nums ,k)) % mod;
}
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& nums, int k) {
        memset(dp,-1,sizeof dp);

        return rec(0, 0 , 0 , nums , k);
    }
};