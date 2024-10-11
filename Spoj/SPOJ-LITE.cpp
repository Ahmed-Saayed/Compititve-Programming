#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll N=1e5+1;
ll n,lef,righ,seg[N*4],lazy[N*4];

void push(int node,int l,int r){
    seg[node]=lazy[node]%2?r-l+1-seg[node]:seg[node];

    if(l!=r){
        lazy[node*2]+=lazy[node],
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
}

ll get(int node=1,int l=1,int r=n){
    push(node,l,r);

    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return get(node*2,l,m)+get(node*2+1,m+1,r);
}

void up(int node=1,int l=1,int r=n){
    push(node,l,r);

    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        lazy[node]++;
        push(node,l,r);
        return;
    }

    int m=l+r>>1;
    up(node*2,l,m),
    up(node*2+1,m+1,r);

    seg[node]=seg[node*2]+seg[node*2+1];
}

int main()
{
Ahmed_Sayed();
int q;cin>>n>>q;

while(q--){
    int o;cin>>o>>lef>>righ;
    if(!o)up();
    else cout<<get()<<'\n';
}
}
//
