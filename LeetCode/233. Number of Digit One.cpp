#define ll long long

string s;
ll dp[11][2][11];
ll rec(int i = 0, int f1 = 0, int p = 0){
    if(i == s.size())return p;

    ll & ret = dp[i][f1][p], mx = !f1? s[i] - '0' : 9;
    if(~ret)return ret;
    
    ret = 0;
    for(int j = 0; j <= mx ;j++)
        ret += rec(i + 1, !( !f1 && j == mx), p + (j == 1));

    return ret;
}


class Solution {
public:
    int countDigitOne(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof dp);

        return rec();
    }
};