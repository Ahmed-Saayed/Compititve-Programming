#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int dx[9]={0,0,0,1,-1,1,-1,1,-1};
int dy[9]={0,-1,1,0,0,1,1,-1,-1},n,m,s1,s2,e1,e2;
int grid[40][40];


ll bfs(){
    ll dis[n][m][8][8];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<8;k++)for(int k2=0;k2<8;k2++)dis[i][j][k][k2]=1e9;

    queue<array<ll,5>>q;
    q.push({0,s1,s2,0,0});

    while(q.size()){
        auto[cost,x,y,sp1,sp2]=q.front();q.pop();

        if(cost>dis[x][y][sp1+3][sp2+3])continue;
        dis[x][y][sp1+3][sp2+3]=cost;

        if(x==e1&&y==e2)return cost;

        for(int i=0;i<9;i++){
            ll a=sp1+dx[i],b=sp2+dy[i],jump1=x+a,jump2=y+b;

            if(abs(a)<4&&abs(b)<4&&jump1>=0&&jump1<n&&jump2>=0&&jump2<m&&!grid[jump1][jump2]&&cost+1<dis[jump1][jump2][a+3][b+3])
                dis[jump1][jump2][a+3][b+3]=cost+1,
                q.push({cost+1,jump1,jump2,a,b});
        }
    }
    return -1;
}

int main()
{
Ahmed_Sayed();
tt
cin>>n>>m>>s1>>s2>>e1>>e2;
for(int i=0;i<n;i++)for(int j=0;j<m;j++)grid[i][j]=0;

ll k;cin>>k;
while(k--){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    for(int i=a;i<=b;i++)
        for(int j=c;j<=d;j++)grid[i][j]=1;
}

ll ans=bfs();
if(~ans)cout<<"Optimal solution takes "<<ans<<" hops.";
else cout<<"No solution.";
nn;}
}
//