pair<int,int>conv(int x,int y,int val){
    if(val==1)return {x,++y};
    if(val==2)return {x,--y};
    if(val==3)return {++x,y};
    if(val==4)return {--x,y};

    return {};
}

bool valid(int i,int j,int n,int m){
    return i>=0&&j>=0&&j<m&&i<n;
}

int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};

int BFS01(vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size();
    deque<array<int,3>>dq;
    vector<vector<int>>dis(n,vector<int>(m,1e9));

    dq.push_back({0,0,0});
    while(dq.size()){
        auto[cost,i,j]=dq.front();dq.pop_front();

        if(i==n-1&&j==m-1)return cost;

        auto p=conv(i,j,grid[i][j]);
        if(valid(p.first,p.second,n,m)&&cost<dis[p.first][p.second])
            dis[p.first][p.second]=cost,dq.push_front({cost,p.first,p.second});

        for(int k=0;k<4;k++){
            int a=dx[k]+i,b=dy[k]+j;

            if(valid(a,b,n,m)&&cost+1<dis[a][b])
                dis[a][b]=cost+1,dq.push_back({cost+1,a,b});
        }
    }
    return 0;
}

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        return BFS01(grid);
    }
};