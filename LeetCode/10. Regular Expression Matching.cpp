class Solution {
public:
    string ss,pat;
    map<pair<int,string>,int>mp;
    bool rec(int i=0,string t=""){
            if(i==pat.size()||t.size()>ss.size()+2||(t.size()>1&&ss[t.size()-2]!=t[t.size()-2]))return ss==t;

            if(mp.count({i,t}))return mp[{i,t}];

            int&ret=mp[{i,t}];
            if(pat[i]!='.'&&pat[i]!='*')
                ret|=rec(i+1,t+pat[i]);

            else if(pat[i]=='.')
                ret|=rec(i+1,t+ss[t.size()]);

            else{
                char ch=t.back();
                t.pop_back();

                for(int k=0;k<20&&t.size()<ss.size()+1;k++){
                    ret|=rec(i+1,t),
                    t+=(pat[i-1]=='.'?ss[t.size()]:ch);
                }
            }

            return ret;
    }

    bool isMatch(string s, string p) {
        ss=s,pat=p;
   

        return rec();
    }
};