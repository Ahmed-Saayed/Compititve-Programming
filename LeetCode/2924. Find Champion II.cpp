class Solution {
public:
vector<int>adj[101],vis;
void dfs(int node, int Fjump){
    if(Fjump)
        vis[node] = 1;

    for(auto i: adj[node])
        if(!vis[i])dfs(i, 1);
}

    int findChampion(int n, vector<vector<int>>& edges) {
        vis=vector<int>(n);

        for(auto i: edges)
            adj[i[0]].push_back(i[1]);

        for(int i = 0 ;i < n ;i++)
            if(!vis[i])dfs(i, 0);

        int Winners = 0, Winner ;
        for(int i = 0; i < n ;i++)
            if(!vis[i])
                Winners++, Winner = i;

        return Winners == 1? Winner : -1;
    }
};