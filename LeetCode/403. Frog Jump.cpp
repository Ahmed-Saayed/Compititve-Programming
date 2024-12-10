    #define all(v) (v).begin(),(v).end()

    const int N = 2000;
    vector<int>x;
    int n, dp[N][N + 1][2];
    int rec(int i, int k, bool p){
        if(i == n - 1)return 1;

        int & ret = dp[i][k][p];
        if(~ret)return ret;

        ret = 0;

        auto it = lower_bound(all(x),x[i] + k + 1);

        if(p && it != x.end() && *it == x[i] + k + 1)
            ret |= rec(it - x.begin(), k + 1, 1);

        it = lower_bound(all(x), x[i] + k);
        if(it != x.end() && *it == x[i] + k)
            ret |= rec(it - x.begin(), k, 1);

        if(k - 1 && p){
            it = lower_bound(all(x), x[i]+ k - 1);

            if(it != x.end() && *it == x[i] + k - 1)
                ret |= rec(it - x.begin(), k - 1, 1);
        }

        return ret;
    }

class Solution {
public:
    bool canCross(vector<int>& stones) {
        n = stones.size(),
        x = stones;

        for(int i = 0 ; i < n; i++){
            x[i] = stones[i];

            for(int j = 0 ; j < N + 1 ;j++)fill(dp[i][j], dp[i][j] + 2, -1);
        }

        return rec(0, 1, 0);
    }
};
