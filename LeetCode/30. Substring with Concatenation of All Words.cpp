class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size(),m=words[0].size();
        map<string,int>mp;
        for(auto i:words)mp[i]++;

        vector<int>ans;
        for(int i=0;i+n*m-1<s.size();i++){
            map<string,int>mp2;
            
            for(int j=i;j-i!=n*m;j+=m)
                mp2[s.substr(j,m)]++;
            
            if(mp2==mp)ans.push_back(i);
        }
        
        return ans;
    }
};