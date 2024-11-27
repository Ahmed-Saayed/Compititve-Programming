class Solution {
public:
    vector<int>adj[501], dp;
    int rec(int i, int n){
        if(i == n - 1)return 0;

        int&ret = dp[i];    
        if(~ret)return ret;

        ret = 1 + rec(i + 1, n);

        for(auto j: adj[i])
            ret = min(ret, 1 + rec(j, n));

        return ret;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;

        for(int i = 0; i < queries.size() ;i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            dp = vector<int>(n, -1);
            ans.push_back(rec(0, n));
        }
        return ans;
    }
};