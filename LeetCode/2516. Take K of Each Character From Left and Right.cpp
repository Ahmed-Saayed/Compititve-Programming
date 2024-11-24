class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>v[3];
        for(int i=0;i<s.size();i++)
            v[s[i]-'a'].push_back(i);

        for(int i=0;i<3;i++)
            if(v[i].size()<k)return -1;

        if(!k)return 0;

        int fre[3]{},ans=1e9;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'a',sm=i+1,mn=1e9;
            fre[ch]++;

        
        for(int j=0;j<3;j++){
          ch=j;
          int rem=k-fre[ch];

            if(rem>0){
                mn=min(mn,v[ch][v[ch].size()-rem]);
            }
        }
        if(mn!=1e9)sm+=s.size()-mn;
        ans=min(ans,sm);
    }
    
      int mn=1e9;
      for(int j=0;j<3;j++)
            mn=min(mn,v[j][v[j].size()-k]);
        
        ans=min(ans,(int)s.size()-mn);

      return ans;
}
};