#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int fix(int n,int mod){return (n%mod+mod)%mod;}

int main()
{
Ahmed_Sayed();
tt
int n,d;cin>>n>>d;
int v[n],vis[n]{};
for(auto&i:v)cin>>i;

for(int i=0;i<n;i++){
    if(!v[i]&&!vis[i]){
        int j=fix(i-d,n),c=1;

        while(v[j])
            v[j]=0,vis[j]=c++,j=fix(j-d,n);
    }
}

cout<<(*max_element(v,v+n)?-1:*max_element(vis,vis+n))<<'\n';}
}