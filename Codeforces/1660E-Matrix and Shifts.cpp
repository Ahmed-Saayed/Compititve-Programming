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
int n;cin>>n;
int pre[n]{};
char x[n][n];
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>x[i][j],pre[i]+=x[i][j]=='1';

int ans=1e9;
for(int i=0;i<n;i++){
    int sm=0,o=0,row=i;

    while(o<n){
        sm+=(x[row][o]=='0')+pre[row]-(x[row][o++]=='1');
        row=(row+1)%n;
    }

    ans=min(ans,sm);
}

cout<<ans<<'\n';}
}