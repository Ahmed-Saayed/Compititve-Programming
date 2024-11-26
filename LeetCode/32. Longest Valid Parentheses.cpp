class Solution {
public:
    struct st{
        int l, r, res;
    };
    st seg[(int)4e5];

    st merge(st x, st y){
        st ret;

        int mn = min(x.l, y.r);
        ret.res = mn + x.res + y.res,
        ret.l = x.l + y.l - mn,
        ret.r = y.r + x.r - mn;

        return ret;
    }

    string t;
    void bul(int node,int l,int r){
        if(l == r){
            (t[l] == '('?seg[node].l++ :seg[node].r++);
            return;
        }

        int m = (l+r) >>1;
        bul(node * 2, l, m),
        bul(node * 2 + 1 ,m + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    st get(int node, int l, int r, int lef, int righ){
        if(l > righ || r < lef)return {};
        if(l >= lef && r <= righ)return seg[node];

        int m = (l + r) >>1;
        return merge(get(node * 2, l, m, lef, righ), get(node * 2 + 1, m + 1, r, lef, righ));
    }

    int close[(int)1e5],dp[(int)1e5][2];
    int rec(int i = 1, int open = 0){
        if(i >= t.size())return 0;

        int&ret = dp[i][open];
        if(~ret)return ret;

        ret = 0;
        if(!open)
            ret = rec(i + 1, 0);

        if(t[i] == '(' && get(1, 1, t.size() - 1, i, close[i]).res * 2 == close[i] - i + 1)
            ret = max(ret, close[i] - i + 1 + rec(close[i] + 1, 1));

        return ret;
    }


    int longestValidParentheses(string s) {
        if(!s.size())return 0;
        s = '*' + s, t = s,
        memset(dp, -1, sizeof dp),
        bul(1, 1, s.size() - 1);

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