class Solution {
public:
    bool ok(int i ,int j,int n,int m){
        return min(i,j)>=0 && i<n && j<m;
    }
    
    int trapRainWater(vector<vector<int>>& x) {
        int n=x.size(),m=x[0].size(),dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};

        vector<vector<int>>vis(n,vector<int>(m));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>>pq;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!min(i,j)||i==n-1||j==m-1)pq.push({x[i][j],i,j}),vis[i][j]=1;

        int ans=0;
        while(pq.size()){
            auto[cost,i,j]=pq.top();pq.pop();

            ans+=cost-x[i][j];

            for(int k=0;k<4;k++){
                int a=dx[k]+i,b=dy[k]+j;

                if(ok(a,b,n,m)&&!vis[a][b])
                    vis[a][b]=1,pq.push({max(x[a][b],cost),a,b});
            }
        }

        return ans;
    }
};