#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+5;
ll n,x[N],gc[N*4],lef,righ,val;

map<ll,ll>seg[N*4];

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node][x[l]]++;
        gc[node]=x[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),bul(node*2+1,m+1,r);

    for(auto[a,b]:seg[node*2])
        seg[node][a]+=b;

    for(auto[a,b]:seg[node*2+1])
        seg[node][a]+=b;

    gc[node]=__gcd(gc[node*2],gc[node*2+1]);
}

ll get(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)
        return (seg[node].find(val)!=seg[node].end()?seg[node][val]:0);

    int m=l+r>>1;
    return get(node*2,l,m)+get(node*2+1,m+1,r);
}

ll get2(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return gc[node];

    int m=l+r>>1;
    return __gcd(get2(node*2,l,m),get2(node*2+1,m+1,r));
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=1;i<=n;i++)cin>>x[i];
bul();

int q;cin>>q;
while(q--){
    cin>>lef>>righ;
    val=get2();
    
    cout<<(righ-lef+1)-get()<<'\n';
}
}