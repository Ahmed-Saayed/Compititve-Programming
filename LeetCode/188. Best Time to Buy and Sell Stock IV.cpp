const int N = 1e3 + 5;
int n,x[N], dp[N][101];
vector<int>adj[N];
int rec(int i,int k){
    if(i == n)return 0;

    int & ret = dp[i][k];
    if(~ret)return ret;

    ret = rec(i + 1, k);

    if(k)
        for(auto j: adj[i])
            ret = max(ret, x[j] - x[i] + rec(j + 1 , k - 1));

    return ret;
}

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        fill(adj, adj + n + 1, vector<int>());

        for(int i = 0; i < n ;i++)
            x[i] = prices[i], fill(dp[i], dp[i] + k + 1 , -1);

        for(int i = 0 ;i < n ;i++)
            for(int j = i + 1;j < n; j++)
                if(x[j] > x[i])adj[i].push_back(j);

        return rec(0, k);
    }
};