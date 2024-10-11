#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=301;
int sz,n,m,arr[N],grid[N][N],dp[N][N][N];
bool rec(int i=0,int x=0,int y=0){
    if(i==sz||x==n||y==m)return 0;

    int&ret=dp[i][x][y];
    if(~ret)return ret;

    ret=0;

    if(arr[i]==grid[x][y])ret|=!rec(i+1,x+1,y+1);
    ret|=rec(i,x+1,y),
    ret|=rec(i,x,y+1);

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
cin>>sz>>n>>m;
for(int i=0;i<sz;i++){
    cin>>arr[i];

    for(int j=0;j<n;j++)
        for(int k=0;k<m;k++)dp[i][j][k]=-1;
}

for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>grid[i][j];

cout<<(rec()?'T':'N')<<'\n';}
}