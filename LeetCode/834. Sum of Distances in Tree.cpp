const int N = 1e5;
vector<int>adj[N];
vector<int>ans, sz, lvl;
pair<int, int>dfs(int node = 1,int par = 0, int dep = 0){
    int sm = 0, c = 1;

    lvl[node] = dep;

    for(auto i : adj[node])
        if(i != par){
            auto p = dfs(i, node, dep + 1);

            sm += p.first, c += p.second;
        }

    sz[node] = c,
    ans[node] = sm - dep * (c - 1);

    return {sm + dep, c};
}

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        lvl = sz = ans = vector<int>(n + 1);
        fill(adj, adj + n + 1, vector<int>());

        for(auto i : edges){
            adj[i[0] + 1].push_back(i[1] + 1),
            adj[i[1] + 1].push_back(i[0] + 1);
        }

        dfs();

        vector<bool>vis(n + 1);
        queue<int>q;
        q.push(1);
        vis[1] = 1;

        while(q.size()){
            int node = q.front(); q.pop();

            for(auto i : adj[node])
                if(!vis[i]){
                    vis[i] = 1,
                    ans[i] += ans[node] - ans[i] - sz[i] + (n - sz[i]);
                    q.push(i);
                }
        }

        return vector<int>(ans.begin() + 1, ans.end());
    }
};