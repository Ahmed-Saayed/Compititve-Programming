#define ll long long

const int mod = 1e9 + 7;
ll dp[(ll)1e5][2][3];
ll rec(int i, int a, int l, int n){
    if(i == n)return 1;

    ll & ret = dp[i][a][l];					//552. Student Attendance Record II
    if(~ret)return ret;

    ret = rec(i + 1, a, 0, n) % mod;

    if(!a)
        ret = (ret + rec(i + 1, 1, 0, n)) % mod;

    if(l < 2)
        ret = (ret + rec(i + 1, a, l + 1, n)) % mod;

    return ret;
}

class Solution {
public:
    int checkRecord(int n) {
        for(int i = 0; i < n ;i++)
            for(int j = 0; j < 2; j++)fill(dp[i][j], dp[i][j] + 3, -1);

        return rec(0, 0, 0, n);
    }
};