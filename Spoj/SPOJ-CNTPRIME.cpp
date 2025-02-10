#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll N=1e4+1,NN=1e6;
ll n,x[N],lef,righ,val,prime[NN+1];

struct st{
    ll ans,lazy;
};

st seg[N*4];

void push(int node,int l,int r){
    if(seg[node].lazy){
    seg[node].ans=(r-l+1)*!prime[seg[node].lazy];
    if(l!=r){
        seg[node*2].lazy=seg[node].lazy,
        seg[node*2+1].lazy=seg[node].lazy;
    }}
    seg[node].lazy=0;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node].ans=!prime[x[l]];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node].ans=seg[node*2].ans+seg[node*2+1].ans;
}

ll get(int node=1,int l=1,int r=n){
    push(node,l,r);

    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node].ans;

    int m=l+r>>1;
    return get(node*2,l,m)+get(node*2+1,m+1,r);
}

void up(int node=1,int l=1,int r=n){
    push(node,l,r);

    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        seg[node].ans=(r-l+1)*!prime[val];
        if(l!=r){
            seg[node*2].lazy=val,
            seg[node*2+1].lazy=val;
        }
        return;
    }

    int m=l+r>>1;
    up(node*2,l,m),
    up(node*2+1,m+1,r);

    seg[node].ans=seg[node*2].ans+seg[node*2+1].ans;
}
int main()
{
Ahmed_Sayed();
int id=1;
prime[1]=1;
for(int i=2;i<=NN;i++)
    if(!prime[i])
        for(int j=i*2;j<=NN;j+=i)prime[j]=1;

tt
cout<<"Case "<<id++<<":\n";
int q;cin>>n>>q;
for(int i=1;i<N*4;i++)seg[i].ans=seg[i].lazy=0;

for(int i=1;i<=n;i++)cin>>x[i];
bul();

while(q--){
    int o;cin>>o>>lef>>righ;
    if(!o)cin>>val,up();
    else cout<<get()<<'\n';
}}
}
