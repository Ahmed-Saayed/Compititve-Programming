#define ll long long

const int N=1e5;
vector<pair<int,ll>>adj[N];						//3123. Find Edges in Shortest Paths
ll dijkstra(int n){
    vector<ll>dis(n,1e18);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    pq.push({0,0});
    while(pq.size()){
        auto[cost,node]=pq.top();pq.pop();

        if(node==n-1)return cost;

        if(cost>dis[node])continue;
        dis[node]=cost;

        for(auto [a,b]:adj[node])
            if(cost+b<dis[a])
                dis[a]=cost+b,pq.push({cost+b,a});
    }

    return -1;
}

vector<ll>dijkstra2(int n,int sz){
    vector<ll>dis(sz,1e18);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    pq.push({0,n});

    while(pq.size()){
        auto[cost,node]=pq.top();pq.pop();

        if(cost>dis[node])continue;
        dis[node]=cost;

        for(auto [a,b]:adj[node])
            if(cost+b<dis[a])
                dis[a]=cost+b,pq.push({cost+b,a});

    }

    return dis;
}

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        fill(adj,adj+n,vector<pair<int,ll>>());
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]}),
            adj[i[1]].push_back({i[0],i[2]});
        }

        int mn=dijkstra(n);
        if(mn==-1)return vector<bool>(edges.size());

        vector<bool>ans;
        auto dis1=dijkstra2(0,n),dis2=dijkstra2(n-1,n);

        for(auto i:edges)
            ans.push_back((i[2]+dis1[i[0]]+dis2[i[1]]==mn)||(i[2]+dis2[i[0]]+dis1[i[1]]==mn));

        return ans;
    }
};