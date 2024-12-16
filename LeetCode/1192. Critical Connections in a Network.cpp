#define ll long long
const int N=1e5+1;
vector<int>adj[N],low,vis,dn;
set<pair<int,int>>s;
int id=1;
void bridges(ll node,ll par){
    vis[node]=1;
    low[node]=dn[node]=id++;

    for(auto i:adj[node]){
        if(par==i)continue;

        if(!vis[i]){
            bridges(i,node);
            low[node]=min(low[node],low[i]);
            if(low[i]>dn[node])s.insert({node,i});
        }
        else low[node]=min(low[node],dn[i]);
    }
}

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<n;i++)adj[i].clear();
        vis=dn=low=vector<int>(n+1),s.clear(),id=1;

        for(auto i:connections)
            adj[i[0]].push_back(i[1]),
            adj[i[1]].push_back(i[0]);

        for(int i=0;i<n;i++)
            if(!vis[i])bridges(i,-1);

        vector<vector<int>>ans;
        for(auto[a,b]:s)
            ans.push_back(vector<int>{a,b});
            
        return ans;
    }
};