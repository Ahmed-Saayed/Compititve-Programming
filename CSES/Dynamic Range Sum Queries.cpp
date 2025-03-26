#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5,sqr=500;
ll n,x[N],blk[sqr];
vector<ll>blocks[sqr];
void bul(){
    for(int i=0;i<n;i++)
        blocks[i/sqr].push_back(x[i]),
        blk[i/sqr]+=x[i];
}
 
void up(int id,int val){
    blk[id/sqr]-=x[id],
    blk[id/sqr]+=val,
    blocks[id/sqr][id%sqr]=val,
    x[id]=val;
}
 
ll get(int l,int r){
    ll ret=0;
 
    while(l<=r){
        if(l%sqr==0&&l+sqr-1<=r)
            ret+=blk[l/sqr],l+=sqr;
 
        else
            ret+=x[l++];
    }
    return ret;
}
 
int main()
{
Ahmed_Sayed();
int q;cin>>n>>q;
for(int i=0;i<n;i++)cin>>x[i];
 
for(int i=0;i<sqr;i++)
    blocks[i].clear(),blk[i]=0;
 
bul();
 
while(q--){
    int o,l,r;cin>>o;
    if(o==1){
        int id,val;cin>>id>>val;
        up(id-1,val);
    }
    else cin>>l>>r,cout<<get(l-1,r-1)<<'\n';
}
}