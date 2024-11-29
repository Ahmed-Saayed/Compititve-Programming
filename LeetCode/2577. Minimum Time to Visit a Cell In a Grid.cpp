#define ll long long
class Solution {
public:
    int minimumTime(vector<vector<int>>& x) {
        if(x[0][1] > 1 && x[1][0]  > 1)return -1;

        int n = x.size(),m = x[0].size(),dx[4]{1, -1, 0, 0},dy[4]{0, 0, -1, 1};
        vector<vector<ll>>dis(n, vector<ll>(m, 1e18));
        dis[0][0] = 0;

        priority_queue<array<ll, 3>,vector<array<ll, 3>>,greater<>>pq;
        pq.push({0, 0, 0});
        
        while(pq.size()){
            auto[cost, i, j] = pq.top();pq.pop();

            if(i == n - 1 && j == m - 1)return cost;

            for(int k = 0; k < 4; k++){
                int a = i + dx[k], b = j + dy[k];
                if(a < 0 || a == n || b < 0 || b == m)continue;

                ll add = (x[a][b] <= cost + 1 ? 1 : x[a][b] - cost + ((x[a][b] - cost) % 2 == 0));
                if(cost + add < dis[a][b])
                    dis[a][b] = cost + add, pq.push({cost + add , a , b});
            }

        }
        return 0;
    }
};