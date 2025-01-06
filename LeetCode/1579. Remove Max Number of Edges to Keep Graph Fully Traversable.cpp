#define ll long long

struct DSU{
    vector<ll>par,sz;
    ll sm,edges;

    DSU(){}
    DSU(ll n){
        sm=0,edges=n;
        par=sz=vector<ll>(n+1);
        for(int i=0;i<=n;i++)par[i]=i,sz[i]=1;
    }

    int findlead(ll n){
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU op1(n),op2;

        int sz=0;
        for(auto i:edges)
            if(i[0]==3)sz+=op1.merge(i[1],i[2],0);

        op2=op1;

        for(auto i:edges)
            if(i[0]==1)
                sz+=op1.merge(i[1],i[2],0);
            else if(i[0]==2)
                sz+=op2.merge(i[1],i[2],0);

        set<int>st1,st2;
        for(auto i:edges)
            st1.insert({op1.findlead(i[1]),op1.findlead(i[2])}),
            st2.insert({op2.findlead(i[1]),op2.findlead(i[2])});

        if(st1.size()==st2.size()&&st1.size()==1)
            return edges.size()-sz;
        else
            return -1;
    }
};