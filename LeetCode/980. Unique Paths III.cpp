class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int s,s2,ans=0,goal=0,dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};

        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)s=i,s2=j;
                else if(grid[i][j]==2||!grid[i][j])goal++;
            }

        queue<pair<pair<int,int>,pair<int,vector<vector<int>>>>>q;
        q.push({{s,s2},{0,grid}});
        while(q.size()){
            auto[p,p2]=q.front();q.pop();    
            auto [i,j]=p;
            auto[c,grd]=p2;

            if(grid[i][j]==2){
                if(c==goal)ans++;
                continue;
            }

            for(int k=0;k<4;k++){
                int a=dx[k]+i,b=dy[k]+j;

                if(a>=0&&a<grd.size()&&b>=0&&b<grd[0].size()&&(grd[a][b]==2||!grd[a][b]))
                    grd[a][b]=1,q.push({{a,b},{c+1,grd}}),grd[a][b]=0;
            }
        }

        return ans;
    }
};