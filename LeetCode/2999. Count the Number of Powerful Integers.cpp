#define ll long long

string s,t,o;
ll lmt,dp[17][2][2];
ll rec(int i=0,int f1=0,int f2=0){
    if(i==s.size())
       return 1;

    ll&ret=dp[i][f1][f2];
    if(~ret)return ret;

    ret=0;
    int mn=(!f1?s[i]-'0':0),
        mx=(!f2?t[i]-'0':9);

    for(int j=mn;j<=min(lmt,(ll)mx);j++){
        if(i>=s.size()-o.size()){
            if(j+'0'==o[i-(s.size()-o.size())])
                ret+=rec(i+1,!(!f1&&j==mn),!(!f2&&j==mx));
        }
        else
            ret+=rec(i+1,!(!f1&&j==mn),!(!f2&&j==mx));
    }
    return ret;
}

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string ss) {
        lmt=limit,
        s=to_string(start),
        t=to_string(finish),
        o=ss;
        memset(dp,-1,sizeof dp);

        s=string(t.size()-s.size(),'0')+s;

        return rec();
    }
};