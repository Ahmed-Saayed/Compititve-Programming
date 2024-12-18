const int N=200;
int n,x[N][N],dp[N][N];
int rec(int i=0,int j=0){
    if(i==n)return 0;

    int&ret=dp[i][j];
    if(~ret)return ret;

    ret=1e9;

    for(int k=0;k<n;k++){
        if(k==j&&i+1!=n)continue;

        ret=min(ret,x[i][j]+rec(i+1,k));
    }

    return ret;
}
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                x[i][j]=grid[i][j],dp[i][j]=-1;

        int ans=1e9;
        for(int i=0;i<n;i++)
            ans=min(ans,rec(0,i));

        return ans;
    }
};