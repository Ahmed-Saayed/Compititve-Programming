class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans = 1e9;
        vector<int>adj[n+1];
        vector<vector<int>>s(401,vector<int>(401));

        for(auto i:edges){
            s[min(i[0],i[1])][max(i[0],i[1])]++;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(int i=1;i<=n;i++)
            for(auto j:adj[i])
                for(auto k:adj[j]){
                      if(s[i][k])ans=min(ans, (int)adj[i].size() + (int)adj[j].size() + (int)adj[k].size() - 6);
                }

        return ans == 1e9 ? -1 : ans;
    }
};