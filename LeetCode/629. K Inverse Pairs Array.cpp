class Solution {
public:
    int dp[1001][1001], mod=1e9+7;
    int rec(int n, int k){
        if(!n || !k)return !k;

        int & ret = dp[n][k];
        if(~ret)return ret;

        ret=0;
        for(int j = 0; j <= min(n - 1, k) ;j++){
            ret = (ret + rec(n - 1, k - j)) % mod;
        }

        return ret;
    }

    int kInversePairs(int n, int k) {
        memset(dp, -1 ,sizeof dp);
        return rec(n, k);
    }
};