string s;
vector<string>ans;
map<string, bool>mp;
void rec(int i, string t, string v){
    if(i == s.size()){
        if(!t.size())
            v.pop_back(), ans.push_back(v);

        return;
    }

    t += s[i];

    rec(i + 1, t, v);

    if(mp.count(t))
        v += t + ' ', t = "", rec(i + 1 , t , v);
}

class Solution {
public:
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        mp.clear(), ans.clear();

        for(auto i:wordDict)mp[i] = 1;
        s = str;

        rec(0, "" , "");
        return ans;
    }
};