class Solution {
public:
    int dp[25][25];
    string s;
    int rec(int i=0,int open=0){
        if(open<0)return -1e8;
        if(i==s.size())return open*-1e8;

        int&ret=dp[i][open];
        if(~ret)return ret;

        ret=rec(i+1,open);

        if(s[i]!='('&&s[i]!=')')
            ret=max(ret,1+rec(i+1,open));
        else
            ret=max(ret,1+rec(i+1,open+(s[i]=='('?1:-1)));

        return ret;
    }

    bool valid(string s){
        int c=0;
        for(auto i:s){
            if(i=='(')c++;
            else if(i==')')c--;

            if(c<0)return 0;
        }

        return !c;
    }

    vector<string> removeInvalidParentheses(string t) {
        memset(dp, -1, sizeof dp),
        s = t;

        int mx = rec(), n = t.size();

        vector<string>ans;

        for(int i=0;i<1<<n;i++){
        if(__builtin_popcount(i)!=mx)continue;

            string t;
            for(int j=0;j<n;j++)
                if(i>>j&1)t+=s[j];

            if(valid(t))ans.push_back(t);
        }

       sort(ans.begin(),ans.end());
       int id=unique(ans.begin(),ans.end())-ans.begin();
       while(ans.size()>id)ans.pop_back();

       return ans;
    }
};