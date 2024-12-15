const int N=1e5+5;
vector<int>adj[N];					
int dijkstra(vector<vector<int>>& x,int source, int target){		//815. Bus Routes
    if(source == target)return 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    for(auto i:adj[source])pq.push({1,i});

    vector<int>dis(x.size(),1e9);
    while(pq.size()){
        auto[cost,line]=pq.top();pq.pop();

        if(cost>dis[line])continue;
        dis[line]=cost;

        for(auto i:x[line]){
            if(i==target)return cost;

            for(auto j:adj[i])
                if(cost+1<dis[j]){
                    dis[j]=cost+1,pq.push({cost+1,j});
            }
        }
    }

    return -1;
}

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<int>v;
        for(int i=0;i<routes.size();i++)
            for(auto j:routes[i])v.push_back(j),adj[j].push_back(i);
            
        int ans=dijkstra(routes,source,target);
        
        for(auto i:v)adj[i].clear();
       
        return ans;
    }
};