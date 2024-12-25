#define all(v) (v).begin(),(v).end()

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
            v[i]={growTime[i],plantTime[i]};

        sort(all(v),greater<>());
        int sm=0,ans=0;
        for(auto[a,b]:v)
            sm+=b,ans=max(ans,sm+a);

        return ans;
    }
};