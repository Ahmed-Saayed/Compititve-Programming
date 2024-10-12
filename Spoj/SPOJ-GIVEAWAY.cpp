#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=5e5+5,sq=800;
vector<vector<int>>blk;
int x[N];
ll get(int l,int r,int val){
    ll ret=0;

    while(l<=r&&l%sq)ret+=x[l++]>=val;
        while(l+sq-1<=r)
            ret+=blk[l/sq].end()-lower_bound(all(blk[l/sq]),val),
            l+=sq;

        while(l<=r)ret+=x[l++]>=val;

    return ret;
}

int main()
{
Ahmed_Sayed();
blk=vector<vector<int>>(sq);

int n,q;
cin>>n;
for(int i=0;i<n;i++)
    cin>>x[i],blk[i/sq].push_back(x[i]);

for(auto&i:blk)sort(all(i));

cin>>q;
while(q--){
    int o;cin>>o;
    if(o){
        int id,val,id2;cin>>id>>val,id--;

        for(int i=0;i<sq;i++)
            if(blk[id/sq][i]==x[id]){id2=i;break;}

        blk[id/sq][id2]=x[id]=val,
        sort(all(blk[id/sq]));
    }
    else{
        int l,r,val;cin>>l>>r>>val;
        cout<<get(--l,--r,val)<<'\n';
    }
}
}
