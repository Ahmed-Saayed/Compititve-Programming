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
int n,m,x,y;cin>>n>>m>>x>>y;
char arr[n+1][m+1];
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)cin>>arr[i][j];

string t;cin>>t;
set<pair<int,int>>ans;
for(auto i:t){
    int a=x,b=y;
    if(i=='U')a--;
    if(i=='D')a++;
    if(i=='L')b--;
    if(i=='R')b++;

    if(a>=1&&a<=n&&b>=1&&b<=m&&arr[a][b]!='#')
        x=a,y=b;

    if(arr[a][b]=='@')
        ans.insert({x,y});
}

cout<<x<<' '<<y<<' '<<ans.size();
}
