
int n,m,dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
vector<vector<int>>x,dp;
int rec(int i,int j){

    int&ret=dp[i][j];
    if(~ret)return ret;

    ret=0;

    for(int k=0;k<4;k++){
        int a=i+dx[k],b=j+dy[k];

        if(min(a,b)>=0&&a<n&&b<m&&x[a][b]>x[i][j])
            ret=max(ret,1+rec(a,b));
    }

    return ret;
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         n=matrix.size(),m=matrix[0].size(),x=matrix;
         dp=vector<vector<int>>(n,vector<int>(m,-1));

         int ans=0,c=0;
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)ans=max(ans,rec(i,j));

         return ++ans;
    }
};