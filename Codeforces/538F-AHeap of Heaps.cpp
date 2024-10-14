#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+1;
int n,x[N],lef,righ,val;
vector<int>seg[N*4];

vector<int>merge(vector<int>x,vector<int>y){
    vector<int>ret;

    int i=0,j=0;
    while(i<x.size()&&j<y.size()){
        if(x[i]<y[j])ret.push_back(x[i++]);
        else ret.push_back(y[j++]);
    }

    while(i<x.size())ret.push_back(x[i++]);
    while(j<y.size())ret.push_back(y[j++]);

    return ret;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node].push_back(x[l]);
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=merge(seg[node*2],seg[node*2+1]);
}

ll get(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return lower_bound(all(seg[node]),val)-seg[node].begin();

    int m=l+r>>1;
    return get(node*2,l,m)+get(node*2+1,m+1,r);
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=1;i<=n;i++)cin>>x[i];
bul();

for(ll i=1;i<n;i++){
        ll ans=0;
    for(int j=1;j<=n;j++){
        lef=i*(j-1)+2,righ=i*j+1,val=x[j];
        if(lef>n)break;

        ans+=get();
    }
    cout<<ans<<' ';
}
}
