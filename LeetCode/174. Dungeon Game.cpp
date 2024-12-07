vector<vector<int>>x,dp;
int rec(int i=0,int j=0){
    if(i == x.size() || j == x[0].size())return 1e9;
    if(i == x.size() -1 && j == x[0].size() - 1)return max(1, 1 - x[i][j]);

    int& ret = dp[i][j];
    if(ret != 1e9)return ret;

     ret = -x[i][j] + min(rec(i + 1, j) ,rec(i, j + 1));

    return ret = max(ret, 1);
}

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        x=dungeon;
        dp=vector<vector<int>>(x.size(),vector<int>(x[0].size(),1e9));
        return rec();
    }
};