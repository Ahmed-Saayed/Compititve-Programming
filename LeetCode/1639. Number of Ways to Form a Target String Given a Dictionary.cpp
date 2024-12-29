#define ll long long

vector<vector<int>>fre;
ll n,dp[(ll)1e3][(ll)1e3],mod=1e9+7;
ll rec(int i,int j,string&t){
    if(i==n||j==t.size())return j==t.size();

    ll &ret=dp[i][j];
    if(~ret)return ret;

    ret=rec(i+1,j,t)%mod;

    if(fre[i][t[j]-'a'])
        ret=(ret+fre[i][t[j]-'a']*rec(i+1,j+1,t))%mod;

    return ret;
}

class Solution {
public:
    int numWays(vector<string>& words, string target) {
       n=words[0].size();
       fre=vector<vector<int>>(n,vector<int>(26));
        memset(dp,-1,sizeof dp);

        for(int i=0;i<words.size();i++)
            for(int j=0;j<n;j++)
                fre[j][words[i][j]-'a']++;

        return rec(0,0,target);
    }
};