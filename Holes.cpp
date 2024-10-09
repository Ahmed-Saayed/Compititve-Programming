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
int n,x[N],nxt[N],cost[N],last[N],sq;
void up(int i){
    if(i/sq!=(i+x[i])/sq||i+x[i]>=n)
        nxt[i]=min(n,i+x[i]),cost[i]=1,last[i]=i;

    else
        nxt[i]=nxt[i+x[i]],cost[i]=1+cost[i+x[i]],last[i]=last[i+x[i]];
}

int main()
{
Ahmed_Sayed();
int q;cin>>n>>q,sq=sqrt(n)+5;
for(int i=0;i<n;i++)cin>>x[i];

for(int i=n-1;~i;i--)up(i);

while(q--){
    int o;cin>>o;
    if(!o){
        int id,val;cin>>id>>val,id--;

        x[id]=val;
        for(int i=id;;i--){
            up(i);

            if(!(i%sq))break;
        }
    }
    else{
        int id;cin>>id,id--;

        int ans1=0,ans2;
        while(id<n){
            ans1+=cost[id],
            ans2=last[id];

            id=nxt[id];
        }

        cout<<++ans2<<' '<<ans1<<'\n';
    }
}
}