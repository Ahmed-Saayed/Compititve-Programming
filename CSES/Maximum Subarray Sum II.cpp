#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--)  {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
vector<ll>pre,seg;
void bul(int node,int l,int r){
    if(l==r){
        seg[node]=pre[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=max(seg[node*2],seg[node*2+1]);
}

ll get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return -1e18;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return max(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

int main()
{
Ahmed_Sayed();
ll n,a,b,ans=-1e18;cin>>n>>a>>b;
pre.assign(n+1,0);
seg.assign(n*4+1,-1e18);

for(int i=1;i<=n;i++)
    cin>>pre[i],pre[i]+=pre[i-1];

bul(1,1,n);

for(int i=1;i+a-1<=n;i++)
    ans=max(ans,get(1,1,n,i+a-1,min(n,i+b-1))-pre[i-1]);

cout<<ans;
}
