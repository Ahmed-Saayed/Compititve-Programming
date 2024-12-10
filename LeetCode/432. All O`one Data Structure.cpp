class AllOne {
public:
    map<string,int>mp;
    set<pair<int,string>>s;
    AllOne() {
    }
    
    void inc(string key) {
        s.erase({mp[key],key});
        mp[key]++;
        s.insert({mp[key],key});
    }
    
    void dec(string key) {
        s.erase({mp[key],key});
        mp[key]--;
        if(mp[key])s.insert({mp[key],key});
    }
    
    string getMaxKey() {
        if(!s.size())return "";
        else return s.rbegin()->second;
    }
    
    string getMinKey() {
        if(!s.size())return "";
        else return s.begin()->second;
    }
};