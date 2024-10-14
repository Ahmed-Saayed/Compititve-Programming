#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
tt
int n,cnt=2;cin>>n;
int endmx[n+2]{},resmx[n+2]{},endmn[n+2]{},resmn[n+2]{};
endmx[1]=resmx[1]=endmn[1]=resmn[1]=1;

while(n--){
    char c;cin>>c;
    if(c=='+'){
        int node,val;cin>>node>>val;

        endmx[cnt]=max(endmx[node]+val,val),
        resmx[cnt]=max(resmx[node],endmx[cnt]),

        endmn[cnt]=min(endmn[node]+val,val),
        resmn[cnt]=min(resmn[node],endmn[cnt]),

        cnt++;
    }
    else{
        int u,v,k;cin>>u>>v>>k;
        
        cout<<(k?k>0?resmx[v]>=k?"YES":"NO":resmn[v]<=k?"YES":"NO":"YES")<<'\n';
    }
}}
}
