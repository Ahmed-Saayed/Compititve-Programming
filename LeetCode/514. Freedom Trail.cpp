class Solution {
public:
    string s,t;
    int dp[100][100];
    int rec(int i = 0, int id = 0){
        if(i == t.size())return t.size();

        int & ret = dp[i][id], mn1 = 0, mn2 = 0, id1, id2;
        if(~ret)return ret;

        if(s[id] == t[i])return ret = rec(i + 1, id);

        for(int j = id + 1 ;; j++){
            if(j == s.size())j = 0;
            mn1++, id1 = j;

            if(s[j] == t[i])break;
        }
        for(int j = id - 1 ;; j--){
            if(j == -1) j= s.size() - 1;
            mn2++, id2 = j;

            if(s[j] == t[i])break;
        }

        return ret = min(mn1 + rec(i + 1, id1), mn2 + rec(i + 1 ,id2));
    }

    int findRotateSteps(string x, string y) {
        s = x, t = y,
        memset(dp, -1, sizeof dp);

        return rec();
    }
};