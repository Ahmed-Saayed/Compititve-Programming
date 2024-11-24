class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& x) {
        map<vector<int>,int>mp;
        

        for(auto i:x){
            vector<int>one,zero;

            for(int j=0;j<i.size();j++)
                if(!i[j])zero.push_back(j);
                else one.push_back(j);
            
            mp[one]++,mp[zero]++;
        }

         int ans=0;
         for(auto[a,b]:mp)ans=max(ans,b);

         return ans;
    }
};