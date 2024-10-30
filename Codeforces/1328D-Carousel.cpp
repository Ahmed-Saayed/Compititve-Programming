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
int n,x[N],dp[N][4][4][2][2][2];
int rec(int i=0,int prev=0,int st=0,int a=0,int b=0,int c=0){
    if(i==n)return (x[n-1]!=x[0]&&st==prev?1e9:a+b+c);

    int&ret=dp[i][prev][st][a][b][c];
    if(~ret)return ret;

    ret=1e9;

    for(int j=1;j<=3;j++){
        if(i&&j==prev&&x[i]!=x[i-1])continue;

        ret=min(ret,rec(i+1,j,(!i?j:st),max(a,int(j==1)),max(b,int(j==2)),max(c,int(j==3))));
    }
    return ret;
}

string bul(int i=0,int prev=0,int st=0,int a=0,int b=0,int c=0){
    if(i==n)return "";

    int best=rec(i,prev,st,a,b,c);

    for(int j=1;j<=3;j++){
        if(i&&j==prev&&x[i]!=x[i-1])continue;

        if(best==rec(i+1,j,(!i?j:st),max(a,int(j==1)),max(b,int(j==2)),max(c,int(j==3))))
            return char(j+'0')+bul(i+1,j,(!i?j:st),max(a,int(j==1)),max(b,int(j==2)),max(c,int(j==3)));
    }
}

int main()
{
Ahmed_Sayed();
tt
cin>>n;
for(int i=0;i<n;i++)
    for(int j=0;j<=3;j++)
        for(int k=0;k<=3;k++)
            for(int l=0;l<2;l++)
                for(int l2=0;l2<2;l2++)
                    for(int l3=0;l3<2;l3++)
                        dp[i][j][k][l][l2][l3]=-1;

for(int i=0;i<n;i++)cin>>x[i];
string ans=bul();

cout<<*max_element(all(ans))<<'\n';
for(auto i:ans)cout<<i<<' ';
nn;}
}
