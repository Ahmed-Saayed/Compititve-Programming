const int N=501;
vector<int>adj[N];
int n;

bool Isbipartite(){             //Check if it Is bipartite
    vector<int>vis(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            vis[i]=0;

            queue<int>q;
            q.push(i);

            while(q.size()){
                int node=q.front();q.pop();

                for(int i:adj[node])
                    if(vis[i]==-1)
                        vis[i]=!vis[node],q.push(i);
                    else if(vis[i]==vis[node])
                        return false;
            }
        }
    }

    return true;
}

int bfs(int node){              // calc the max path for node
    queue<pair<int,int>>q;
    q.push({node,1});

    vector<bool>vis(n+1);
    vis[node]=1;

    int ret=0;
    while(q.size()){
        auto[node,cost]=q.front();q.pop();

        ret=cost;

        for(auto i:adj[node])
            if(!vis[i])vis[i]=1,q.push({i,cost+1});
    }

    return ret;
}

int id,vis[N];
void dfs(int node){            // for store the id for each components 
    vis[node]=id;

    for(auto i:adj[node])
        if(!vis[i])dfs(i);
}

int calc(int val){              // brute force for each node in the component
    int mx=0;
    for(int i=1;i<=n;i++)
        if(vis[i]==val)mx=max(mx,bfs(i));

    return mx;
}

class Solution {
public:
    int magnificentSets(int n2, vector<vector<int>>& edges) {
        n=n2,id=0;
        fill(adj,adj+n+1,vector<int>());
        fill(vis,vis+n+1,0);

        for(auto i:edges)
            adj[i[0]].push_back(i[1]),
            adj[i[1]].push_back(i[0]);

        if(!Isbipartite())return -1;

        for(int i=1;i<=n;i++)
            if(!vis[i])id++,dfs(i);

        vector<int>fre(id+1);
        int ans=0;
        for(int i=1;i<=n;i++)
            if(!fre[vis[i]])
                fre[vis[i]]=1,ans+=calc(vis[i]);

        return ans;
    }
};