vector<int>adj[16],vis;
int dfs(int node,int par){
    int ret=1;

    for(auto i:adj[node])
        if(i!=par&&!vis[i])
            ret+=dfs(i,node);

    return ret;
}

int o,mx;
void dfs2(int node,int par,int dis){
    if(dis>mx)
        mx=dis,o=node;

    for(auto i:adj[node])
        if(i!=par&&!vis[i])dfs2(i,node,dis+1);
}

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        fill(adj,adj+n,vector<int>());
        for(auto i:edges){
            adj[i[0]-1].push_back(i[1]-1),
            adj[i[1]-1].push_back(i[0]-1);
        }

        vector<int>fre(n),ans;

        for(int i=0;i<1<<n;i++){
            vis=vector<int>(n,1);

            int node=-1;
            for(int j=0;j<n;j++){
                if(i>>j&1)
                    vis[j]=0,node=j;
            }

            if(~node&&__builtin_popcount(i)>1&&dfs(node,-1)==__builtin_popcount(i)){
                mx=0,dfs2(node,-1,0);
                mx=0,dfs2(o,-1,0);

                fre[mx]++;
            }
        }

        for(int i=1;i<n;i++)
            ans.push_back(fre[i]);

        return ans;
    }
};