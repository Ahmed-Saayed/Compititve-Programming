string s;
int dp[10][2][2][1 << 10][2];
int rec(int i = 0, bool f2 = 0, int p = 0, int mask = 0, bool put = 0){
    if(i == s.size())return p;

    int & ret = dp[i][f2][p][mask][put], mx = !f2 ? s[i] - '0' : 9;
    if(~ret)return ret;

    ret = 0;
    for(int j = 0; j <= mx; j++)
        ret += rec(i + 1 , !(!f2 && j == mx), p | ((mask >> j & 1) && (put || j > 0)), mask | (j > 0 || put ? (1ll << j) : mask), put | (j > 0));

    return ret;
}
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof dp);

        return rec();
    }
};