const int N=15;
vector<int>adj[N];
int n,dp[12][1ll<<12][22];
int rec(int node,int mask,int cnt){
    if(mask==(1ll<<n)-1||cnt==22)return cnt;

    int&ret=dp[node][mask][cnt];
    if(~ret)return ret;

    ret=1e9;
    for(auto i:adj[node])
        ret=min(ret,rec(i,mask|(1<<i),cnt+1));

    return ret;
}

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        n=graph.size(),memset(dp,-1,sizeof dp);
        fill(adj,adj+n,vector<int>());

        for(int i=0;i<graph.size();i++)
            for(auto j:graph[i])adj[i].push_back(j);

        int ans=50;
        for(int i=0;i<graph.size();i++)
            ans=min(ans,rec(i,1ll<<i,0));

        return ans;
    }
};
