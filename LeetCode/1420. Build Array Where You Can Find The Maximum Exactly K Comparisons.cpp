int n,m,k,dp[50][51][101];
int rec(int i=0,int c=0,int mx=0){
    if(i==n||c>k)return c==k;

    int&ret=dp[i][c][mx];
    if(~ret)return ret;

    ret=0;

    for(int j=1;j<=m;j++)
        ret=(ret+rec(i+1,c+(j>mx),max(mx,j)))%int(1e9+7);

    return ret;
}

class Solution {
public:
    int numOfArrays(int a, int b, int c) {
        n=a,m=b,k=c;
        for(int i=0;i<n;i++)
            for(int j=0;j<=k;j++)
                fill(dp[i][j],dp[i][j]+m+1,-1);

        return rec();
    }
};