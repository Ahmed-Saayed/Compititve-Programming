int ok(int n){
    return max(0,n-1);
}
int n,mod,dp[int(1e4)][7][3][3][3][3][3][3];
class Solution {
public:
    int rec(int i=0,int prev=1,int a=0,int b=0,int c=0,int d=0,int e=0,int f=0){
        if(i==n)return 1;

        int &ret=dp[i][prev][a][b][c][d][e][f];
        if(~ret)return ret;

        ret=0;
        for(int j=1;j<=6;j++){
            if(j==1&&!a&&__gcd(j,prev)==1)
                ret=(ret+rec(i+1,j,2,ok(b),ok(c),ok(d),ok(e),ok(f)))%mod;

            if(j==2&&!b&&__gcd(j,prev)==1)
                ret=(ret+rec(i+1,j,ok(a),2,ok(c),ok(d),ok(e),ok(f)))%mod;

            if(j==3&&!c&&__gcd(j,prev)==1)
                ret=(ret+rec(i+1,j,ok(a),ok(b),2,ok(d),ok(e),ok(f)))%mod;

            if(j==4&&!d&&__gcd(j,prev)==1)
                ret=(ret+rec(i+1,j,ok(a),ok(b),ok(c),2,ok(e),ok(f)))%mod;

            if(j==5&&!e&&__gcd(j,prev)==1)
                ret=(ret+rec(i+1,j,ok(a),ok(b),ok(c),ok(d),2,ok(f)))%mod;

            if(j==6&&!f&&__gcd(j,prev)==1)
                ret=(ret+rec(i+1,j,ok(a),ok(b),ok(c),ok(d),ok(e),2))%mod;
        }

        return ret;
    }
    int distinctSequences(int sz) {
        mod=1e9+7,n=sz;
        memset(dp,-1,sizeof dp);

        return rec();
    }
};