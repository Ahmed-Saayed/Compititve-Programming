#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
struct st{
    ll pre,suf;
};

const int N=5e5+5;
ll n,x[N],pre[N],suf[N];
st seg[N*4];

void bul(int node,int l,int r){
    if(l==r){
        seg[node].pre=pre[l],
        seg[node].suf=suf[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node].pre=max(seg[node*2].pre,seg[node*2+1].pre),
    seg[node].suf=max(seg[node*2].suf,seg[node*2+1].suf);
}

ll get(int node,int l,int r,int lef,int righ,int type){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return(type?seg[node].suf:seg[node].pre);

    int m=l+r>>1;
    return max(get(node*2,l,m,lef,righ,type),get(node*2+1,m+1,r,lef,righ,type));
}

int main()
{
Ahmed_Sayed();
int n;cin>>n;
for(int i=1;i<=n;i++){
    cin>>x[i];

    pre[i]=i+x[i]-1;
}

for(int i=n;i;i--)
    suf[i]=n-i+x[i];

bul(1,1,n);

ll ans=1e18;
for(int i=1;i<=n;i++)
    ans=min(ans,max({get(1,1,n,1,i-1,1),get(1,1,n,i+1,n,0),x[i]}));

cout<<ans;
}
