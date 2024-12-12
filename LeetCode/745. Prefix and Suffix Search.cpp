#define all(v) (v).begin(),(v).end()

class WordFilter {
public:
    map<pair<string,string>,int>mp;
    WordFilter(vector<string>& x) {
        for(int i=0;i<x.size();i++){
            string s;

            for(int j=0;j<x[i].size();j++){
                s+=x[i][j];

                string t;
                for(int k=x[i].size()-1;~k;k--){
                    t+=x[i][k];

                    reverse(all(t)),
                    mp[{s,t}]=max(mp[{s,t}],i);
                    reverse(all(t));
                }
            }
        }
    }

    int f(string pref, string suff) {
        if(mp.count({pref,suff}))
            return mp[{pref,suff}];

        else
            return -1;
    }
};