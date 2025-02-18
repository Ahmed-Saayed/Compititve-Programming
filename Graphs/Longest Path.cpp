class Solution {
public:
    int mx, o;
    void dfs(int node, int par, int d, vector<vector<int>>&adj){	//3203. Find Minimum Diameter After Merging Two Trees
        if(d > mx)
            mx = d, o = node;

        for(auto i : adj[node])
            if(i != par)dfs(i, node, d + 1, adj);
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>>adj1(n + 1), adj2(m + 1);
        
        for(auto i : edges1)
            adj1[i[0] + 1].push_back(i[1] + 1),
            adj1[i[1] + 1].push_back(i[0] + 1);

        for(auto i : edges2)
            adj2[i[0] + 1].push_back(i[1] + 1),
            adj2[i[1] + 1].push_back(i[0] + 1);

        mx = 0, o = 0;
        dfs(1, 0, 0, adj1);
        dfs(o, 0, 0, adj1);

        int ans = (mx + 1) >> 1, dis1 = mx, dis2;

        mx = 0, o = 0;
        dfs(1, 0, 0, adj2);
        dfs(o, 0, 0, adj2);

        ans += (mx + 1) >> 1, dis2 = mx;

        return max({++ans, dis1, dis2});
    }
};