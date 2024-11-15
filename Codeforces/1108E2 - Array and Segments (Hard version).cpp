#include <bits/stdc++.h>
#define ll int
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+5;
int n,x[N];

struct st{
    ll mn,lazy;
};

st seg[N*4];
void push(int node,int l,int r){
    seg[node].mn+=seg[node].lazy;

    if(l!=r){
        seg[node*2].lazy+=seg[node].lazy,
        seg[node*2+1].lazy+=seg[node].lazy;
    }
    seg[node].lazy=0;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node].mn=x[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node].mn=min(seg[node*2].mn,seg[node*2+1].mn);
}


void up(int node,int l,int r,int lef,int righ,int op){
    push(node,l,r);

    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        seg[node].lazy+=op,
        push(node,l,r);
        return;
    }

    int m=l+r>>1;
    up(node*2,l,m,lef,righ,op),
    up(node*2+1,m+1,r,lef,righ,op);

    seg[node].mn=min(seg[node*2].mn,seg[node*2+1].mn);
}

int main()
{
Ahmed_Sayed();
int m;cin>>n>>m;
pair<int,int>y[m];
for(int i=1;i<=n;i++)cin>>x[i];
for(auto&[a,b]:y)cin>>a>>b;

bul();

vector<int>out,vis(m+1);
ll ans=-1e18;
for(int i=1;i<=n;i++){

    for(int j=0;j<m;j++){
        if(y[j].first<=i&&i<=y[j].second&&vis[j])
            up(1,1,n,y[j].first,y[j].second,1),vis[j]=0;

        if(!(y[j].first<=i&&i<=y[j].second)&&!vis[j])
            up(1,1,n,y[j].first,y[j].second,-1),vis[j]=1;
    }

    ll sm=x[i]-seg[1].mn;
    if(sm>ans){
        ans=sm;

        out.clear();
        for(int j=0;j<m;j++)
            if(vis[j])out.push_back(j+1);
    }
}

cout<<ans<<'\n'<<out.size()<<'\n';
for(auto i:out)cout<<i<<' ';
}
