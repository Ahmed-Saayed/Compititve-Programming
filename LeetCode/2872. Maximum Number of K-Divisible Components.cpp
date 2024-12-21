#define ll long long

const int N = 1e5;
vector<int>val, adj[N];
int k, ans;
ll dfs(int node = 0, int par = -1){
    ll ret = val[node];
    for(auto i : adj[node])
        if(i != par)ret += dfs(i, node);

    if(ret % k == 0)
        ans++, ret = 0;

    if(!node && ret % k)ans--;

    return ret;
}
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k2) {
        fill(adj, adj + n, vector<int>());
        val = values, k = k2, ans = 0;

        for(auto i : edges){
            adj[i[0]].push_back(i[1]),
            adj[i[1]].push_back(i[0]);
        }

        dfs();
        return ans;
    }
};