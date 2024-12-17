int n,m,dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
bool dfs(int i,int j,int md,vector<vector<int>>& grid,vector<vector<bool>>&vis){
    if(grid[i][j]>md)return 0;
    if(i==n-1&&j==m-1)return 1;

    vis[i][j]=1;
    bool ret=0;
    for(int k=0;k<4;k++){
        int a=dx[k]+i,b=dy[k]+j;

        if(a>=0&&a<n&&b>=0&&b<m&&!vis[a][b])
            ret|=dfs(a,b,md,grid,vis);
    }

    return ret;
}
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();

        int l=0,r=1e6,md;
        while(l<=r){
            md=(l+r)>>1;
            vector<vector<bool>>vis(n,vector<bool>(m));

            (dfs(0,0,md,grid,vis)?r=md-1:l=md+1);
        }

        return l;
    }
};