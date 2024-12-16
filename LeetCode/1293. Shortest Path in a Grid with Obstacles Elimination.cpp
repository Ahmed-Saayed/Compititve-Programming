int dx[4]{0,0,1,-1},dy[4]{1,-1,0,0},n,m,dp[50][50][50*50];
int rec(int i,int j,int kk,vector<vector<int>>& grid, int k){
    if(kk>k)return 1e9;
    if(i==n-1&&j==m-1)return 0;

    int&ret=dp[i][j][kk];
    if(~ret)return ret;

    ret=1e9;

    for(int o=0;o<4;o++){
        int a=dx[o]+i,b=dy[o]+j;

        if(a>=0&&a<n&&b>=0&&b<m)
            ret=min(ret,1+rec(a,b,kk+grid[a][b],grid,k));
    }

    return ret;
}

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                fill(dp[i][j],dp[i][j]+n*m+5,-1);

        int ans=rec(0,0,0,grid,k);
        return ans==1e9?-1:ans;
    }
};