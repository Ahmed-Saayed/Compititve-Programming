class Solution {
public:
    int BFS_01(vector<vector<int>>grid){
        int n = grid.size(), m = grid[0].size();

        vector<int>dx{1 , -1 ,0 ,0},dy{0 ,0 , 1, -1};
        vector<vector<int>>dis(n, vector<int>(m, 1e9));

        deque<pair<int,int>>dq;
        dq.push_back({0, 0});
        dis[0][0] = grid[0][0];

        while(dq.size()){
            auto[i, j] = dq.front();
            dq.pop_front();

            if(i == n - 1 && j == m - 1)return dis[i][j];

            for(int k = 0 ;k < 4; k++){
                int x = i + dx[k], y = j + dy[k];

                if(x >= 0 && x < n && y >= 0 && y < m && dis[i][j] + grid[x][y] < dis[x][y]){
                    dis[x][y] = dis[i][j] + grid[x][y];
                   
                    (grid[x][y] ? dq.push_back({x, y}): dq.push_front({x, y}));
                }
            }
        }

        return 0;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        return BFS_01(grid);
    }
};