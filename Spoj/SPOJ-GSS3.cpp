#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct st{
    int ans,pre,suf,sm;
};

const int N=1e5;
st seg[N*4];
ll n,x[N],id,val,lef,righ;

st merge(st x,st y){
    st ret;

    ret.ans=max({x.ans,y.ans,x.suf+y.pre});
    ret.pre=max({x.pre,x.sm+y.pre});
    ret.suf=max({y.suf,y.sm+x.suf});
    ret.sm=x.sm+y.sm;

    return ret;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node].ans=seg[node].pre=seg[node].suf=seg[node].sm=x[l];
        return;
    }

    int m=(l+r)/2;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=merge(seg[node*2],seg[node*2+1]);
}

st get(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return {(ll)-1e9,(ll)-1e9,(ll)-1e9,0};
    if(l>=lef&&r<=righ)return seg[node];

    int m=(l+r)/2;
    return merge(get(node*2,l,m),get(node*2+1,m+1,r));
}

void up(int node=1,int l=1,int r=n){
    if(l>id||r<id)return;
    if(l==r){
        seg[node].ans=seg[node].pre=seg[node].suf=seg[node].sm=val;
        return;
    }

    int m=(l+r)/2;
    up(node*2,l,m),
    up(node*2+1,m+1,r);

    seg[node]=merge(seg[node*2],seg[node*2+1]);
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=1;i<=n;i++)cin>>x[i];
bul();

int q;cin>>q;
while(q--){
    int o;cin>>o;
    if(!o)cin>>id>>val,up();
    else cin>>lef>>righ,cout<<get().ans<<'\n';
}
}
