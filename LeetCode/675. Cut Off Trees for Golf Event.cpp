#define all(v) (v).begin(),(v).end()

class Solution {
public:
    int cutOffTree(vector<vector<int>>& x) {
        int n=x.size(),m=x[0].size();

        vector<int>v;
        for(auto i:x)
            for(auto j:i)v.push_back(j);

        sort(all(v));

        int id=0,dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
        while(id<v.size()&&v[id]<=1)id++;

        int i=0,j=0,ans=0;
        while(id<v.size()){
            vector<vector<bool>>vis(n,vector<bool>(m));
            bool p=0;
            queue<array<int,3>>q;
            q.push({0,i,j});
            while(q.size()){
                auto[cost,a,b]=q.front();q.pop();

                if(x[a][b] == v[id]){
                    ans+=cost,p=1,
                    i=a,j=b;
                    break;
                }

                for(int k=0;k<4;k++){
                    int o=a+dx[k],o2=b+dy[k];

                    if(o>=0&&o<n&&o2>=0&&o2<m&&x[o][o2]&&!vis[o][o2])
                        vis[o][o2]=1,q.push({cost+1,o,o2});
                }
            }
            if(!p)break;
            id++;
        }

        return id==v.size()?ans:-1;
    }
};