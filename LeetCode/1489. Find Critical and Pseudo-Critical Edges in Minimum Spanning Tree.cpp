#define ll long long
#define all(v) (v).begin(),(v).end()

struct DSU{
    vector<ll>par,sz;
    ll sm,edges;

    DSU(ll n){
        sm=0,edges=n;
        par=sz=vector<ll>(n+1);
        for(int i=0;i<=n;i++)par[i]=i,sz[i]=1;
    }

    ll findlead(ll n){
        if(par[n]==n)return n;
        return par[n]=findlead(par[n]);
    }

    bool merge(ll x,ll y,ll c){
        x=findlead(x),y=findlead(y);
        if(x==y)return 0;

        sm+=c,edges--;
        if(sz[x]>=sz[y])sz[x]+=sz[y],par[y]=x;
        else sz[y]+=sz[x],par[x]=y;
        return 1;
}
};

class Solution {
public:
    int calc(int n,vector<array<int,4>>v,int id){
        DSU op(n);

        for(auto i:v)
            if(i[3]!=id)op.merge(i[1],i[2],i[0]);

        return op.sm;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<array<int,4>>v;
        for(int i=0;i<edges.size();i++)
            v.push_back({edges[i][2],edges[i][0],edges[i][1],i});

        sort(all(v));

        int cost=calc(n,v,-1);
        vector<int>ans1,ans2;

        for(int i=0;i<edges.size();i++){
            auto tmp=v;
            tmp.insert(tmp.begin(),{edges[i][2],edges[i][0],edges[i][1],i});

            if(calc(n,tmp,-1)==cost){
                if(calc(n,v,i)!=cost)
                    ans1.push_back(i);

                else
                    ans2.push_back(i);
            }
        }

        return {ans1,ans2};
    }
};