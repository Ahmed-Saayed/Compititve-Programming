class Solution {
public:
    string s,t;
    int dp[1000][1000];
    int rec(int i=0,int j=0){
        if(j == t.size())return 1;
        if(i == s.size())return 0;

        int&ret = dp[i][j];
        if(~ret) return ret;
        
        ret = rec(i + 1 ,j);

        if(s[i] == t[j])
            ret += rec(i+1 , j+1);

        return ret;
    }

    int numDistinct(string x, string y) {
        s =x ,t = y,
        memset(dp, -1 ,sizeof dp);

        return rec();
    }
};