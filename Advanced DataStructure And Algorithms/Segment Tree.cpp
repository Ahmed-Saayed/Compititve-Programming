#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

const int N=1e5+5;			//RMQSQ - Range Minimum Query

int seg[N*4];
vector<int>x;

void bul(int node,int l,int r){
    if(l == r){
        seg[node] = x[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=min(seg[node*2],seg[node*2+1]);
}

int get(int node,int l,int r,int lef,int righ){
    if(l>righ || r<lef)return 1e9;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return min(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

int main()
{
Ahmed_Sayed();
int n, q;cin>>n;
x=vector<int>(n+1);
for(int i=1;i<=n;i++)cin>>x[i];
bul(1,1,n);

cin>>q;
while(q--){
    int l, r;cin>> l>> r;

    cout<<get(1,1,n,++l,++r)<<'\n';
}
}
