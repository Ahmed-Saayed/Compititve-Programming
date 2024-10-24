#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
int n,dp[2][N][2];
char x[2][N];

bool check(int i,int j){
    return x[i][j]=='1'||x[i][j]=='2';
}

bool rec(int i=0,int j=0,int o=0){
    if(j==n)return i;

    int&ret=dp[i][j][o];
    if(~ret)return ret;

    ret=0;

    if(check(i,j)||(o&&!check(i,j)))
        ret|=rec(i,j+1,0);

    if(!o&&!check(i,j)&&!check(!i,j))
        ret|=rec(!i,j,1);

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
cin>>n;
for(int i=0;i<2;i++)
    for(int j=0;j<n;j++)
        cin>>x[i][j],dp[i][j][0]=dp[i][j][1]=-1;

cout<<(rec()?"YES":"NO")<<'\n';}
}
