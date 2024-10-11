#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int n,m,s1,s2,e1,e2,o,v[60][60];
string s;

bool valid(ll x,ll y,ll dir,ll dis){
    if(!dir){
            if(x-dis-1<0)return 0;
        for(int i=x;i>=x-dis;i--){
            if(v[i][y]||v[i-1][y]||v[i-1][y-1]||v[i][y-1])return 0;
        }
        return 1;
    }
    if(dir==1){
            if(x+dis>=n)return 0;
        for(int i=x;i<=x+dis;i++){
            if(v[i][y]||v[i-1][y]||v[i-1][y-1]||v[i][y-1])return 0;
        }
        return 1;
    }
    if(dir==2){
            if(y+dis>=m)return 0;
        for(int i=y;i<=y+dis;i++){
            if(v[x][i]||v[x-1][i]||v[x-1][i-1]||v[x][i-1])return 0;
        }
        return 1;
    }
        if(y-dis-1<0)return 0;
    for(int i=y;i>=y-dis;i--){
        if(v[x][i]||v[x-1][i]||v[x-1][i-1]||v[x][i-1])return 0;
    }
    return 1;
}

ll bfs(){
    ll dis[n][m][4];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<4;k++)dis[i][j][k]=1e9;

    queue<array<ll,4>>q;
    q.push({0,s1,s2,o});

    while(q.size()){
        auto[cost,x,y,dir]=q.front();q.pop();

        if(cost>dis[x][y][dir])continue;
        dis[x][y][dir]=cost;

        if(x==e1&&y==e2)return cost;

        if(!dir){
        if(cost+1<dis[x][y][2]){
            dis[x][y][2]=cost+1,q.push({cost+1,x,y,2});
        }
        if(cost+1<dis[x][y][3]){
            dis[x][y][3]=cost+1,q.push({cost+1,x,y,3});
        }
    }
        if(dir==1){
        if(cost+1<dis[x][y][2]){
            dis[x][y][2]=cost+1,q.push({cost+1,x,y,2});
        }
        if(cost+1<dis[x][y][3]){
            dis[x][y][3]=cost+1,q.push({cost+1,x,y,3});
        }
    }
        if(dir==2){
        if(cost+1<dis[x][y][0]){
            dis[x][y][0]=cost+1,q.push({cost+1,x,y,0});
        }
        if(cost+1<dis[x][y][1]){
            dis[x][y][1]=cost+1,q.push({cost+1,x,y,1});
        }
    }
        if(dir==3){
        if(cost+1<dis[x][y][0]){
            dis[x][y][0]=cost+1,q.push({cost+1,x,y,0});
        }
        if(cost+1<dis[x][y][1]){
            dis[x][y][1]=cost+1,q.push({cost+1,x,y,1});
        }
    }

        for(int i=1;i<=3;i++){
            if(!valid(x,y,dir,i))continue;

            if(!dir){
                if(cost+1<dis[x-i][y][dir])dis[x-i][y][dir]=cost+1,q.push({cost+1,x-i,y,dir});
            }
            if(dir==1){
                if(cost+1<dis[x+i][y][dir])dis[x+i][y][dir]=cost+1,q.push({cost+1,x+i,y,dir});
            }
            if(dir==2){
                if(cost+1<dis[x][y+i][dir])dis[x][y+i][dir]=cost+1,q.push({cost+1,x,y+i,dir});
            }
            if(dir==3){
                if(cost+1<dis[x][y-i][dir])dis[x][y-i][dir]=cost+1,q.push({cost+1,x,y-i,dir});
            }

        }

    }
    return -1;
}

int main()
{
Ahmed_Sayed();
//freopen("output.txt", "w", stdout);
while(cin>>n>>m&&n){

for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        cin>>v[i][j];
    }

cin>>s1>>s2>>e1>>e2>>s;

if(s=="north")o=0;
if(s=="south")o=1;
if(s=="east")o=2;
if(s=="west")o=3;
if(!s1||!s2||!e1||!e2||s1==n||s2==m||e1==n||e2==m)cout<<-1;
else cout<<bfs();
nn;}
}
//