class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),ans=1e9,dx[4]{1,-1,0,0},dy[4]{0,0,-1,1};
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)v.push_back({i,j});

        for(int i=0;i<1<<v.size();i++){
            auto tmp=mat;
            
            if(__builtin_popcount(i)>ans)continue;

            for(int j=0;j<v.size();j++){
                if(i>>j&1){
                    auto[a,b]=v[j];

                    tmp[a][b]=!tmp[a][b];

                    for(int k=0;k<4;k++){
                        int a2=a+dx[k],b2=b+dy[k];

                        if(a2>=0&&a2<n&&b2>=0&&b2<m)tmp[a2][b2]=!tmp[a2][b2];
                    }
                }
            }

            int c=0;
            for(auto i:tmp)c+=count(i.begin(),i.end(),1);

            if(!c)ans=min(ans,__builtin_popcount(i));
        }

        return ans==1e9?-1:ans;
    }
};