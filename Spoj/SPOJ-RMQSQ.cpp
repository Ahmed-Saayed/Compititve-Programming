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
ll n,x[N],seg[N*4],lef,righ;
void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node]=x[l];
        return;
    }

    int m=(l+r)/2;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node] = min(seg[node*2] , seg[node*2+1]);
}

ll get(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return 1e18;
    if(l>=lef&&r<=righ){
        return seg[node];
    }

    int m=(l+r)/2;
    return min(get(node*2,l,m),get(node*2+1,m+1,r));
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=1;i<=n;i++)cin>>x[i];
bul();

int q;cin>>q;
while(q--){
    cin>>lef>>righ,lef++,righ++;
    cout<<get()<<'\n';
}
}
//