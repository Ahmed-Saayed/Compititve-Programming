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
int x[N],seg[N*4];
void bul(int node,int l,int r){
    if(r<l)return;
    if(l==r){
        seg[node]=abs(x[l]-x[l+1]);
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=__gcd(seg[node*2],seg[node*2+1]);
}

int get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return __gcd(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

int main()
{
Ahmed_Sayed();
tt
int n,q;cin>>n>>q;

fill(seg,seg+n*4+1,0);

for(int i=1;i<=n;i++)cin>>x[i];
bul(1,1,n-1);

while(q--){
    int l,r;cin>>l>>r,
    cout<<get(1,1,n-1,l,r-1)<<' ';
}
nn;}
}
