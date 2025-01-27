class Solution {
public: 
    string t;
    int close[(int)1e5],dp[(int)1e5][2];
    int rec(int i = 1, int open = 0){
        if(i >= t.size())return 0;

        int&ret = dp[i][open];
        if(~ret)return ret;

        ret = 0;
        if(!open)
            ret = rec(i + 1, 0);

        if(t[i] == '(' && close[i] != 1e9)
            ret = max(ret, close[i] - i + 1 + rec(close[i] + 1, 1));

        return ret;
    }


    int longestValidParentheses(string s) {
        if(!s.size())return 0;
        s = '*' + s, t = s,
        memset(dp, -1, sizeof dp);

        stack<int>st;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '(')st.push(i);
            else if(st.size())
                close[st.top()] = i, st.pop();
        }
        while(st.size())
            close[st.top()] = 1e9, st.pop();

        return rec();
    }
};