
class Solution {
public:
    int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
    bool bfs(vector<vector<bool>>&x){
        int n=x.size(),m=x[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
            if(!x[0][i])q.push({0,i});

        while(q.size()){
            auto[i,j]=q.front();q.pop();

            x[i][j]=1;
            if(i==n-1)return 1;

            for(int k=0;k<4;k++){
                int a=dx[k]+i,b=dy[k]+j;

                if(a>=0&&a<n&&b>=0&&b<m&&!x[a][b])
                    x[a][b]=1,q.push({a,b});
            }
        }

        return 0;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0,r=cells.size()-1;
        while(l<=r){
            int m=l+r>>1;

            vector<vector<bool>>x(row,vector<bool>(col));
            for(int i=0;i<=m;i++)
                x[cells[i][0]-1][cells[i][1]-1]=1;

            (bfs(x)?l=m+1:r=m-1);
        }

        return ++r;
    }
};