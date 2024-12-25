#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
 
const int N=2e5+5;
vector<int>adj[N],v;
int timer=1,val[N],in[N],out[N],n;
 
ll seg[N*8];
void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node] = v[l];
        return;
    }
 
    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);
 
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
 
ll get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];
 
    int m=l+r>>1;
    return get(node*2,l,m,lef,righ) + get(node*2+1,m+1,r,lef,righ);
}
 
void up(int node,int l,int r,int id,ll num){
    if(l>id||r<id)return;
    if(l==r){
        v[l]=seg[node]=num;
        return;
    }
 
    int m=l+r>>1;
    up(node*2,l,m,id,num),
    up(node*2+1,m+1,r,id,num);
 
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
 
void dfs(int node=1,int par=-1){
    in[node]=timer++;
    v.push_back(val[node]);
 
    for(auto i:adj[node])
        if(i!=par)dfs(i,node);
 
    out[node]=timer++,
    v.push_back(0);
}
 
int main()
{
Ahmed_Sayed();
int sz,q;cin>>sz>>q;
for(int i=1;i<=sz;i++)cin>>val[i];
for(int i=0;i<sz-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
v.push_back(0);
dfs(),n=v.size()-1,bul();
 
while(q--){
    int o;cin>>o;
 
    if(o==1){
        int node,num;cin>>node>>num;
        up(1,1,n,in[node],num);
    }
    else{
        int node;cin>>node,
        cout<<get(1,1,n,in[node],out[node])<<'\n';
    }
}
}
