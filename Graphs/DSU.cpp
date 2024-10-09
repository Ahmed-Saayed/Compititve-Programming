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