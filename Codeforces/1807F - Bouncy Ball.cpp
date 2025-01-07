#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int n,m,i2,j2;
bool ok(char c1,char c2,int i1,int j1){
    if(i1>=i2&&j1>=j2&&c1=='U'&&c2=='L')
        return i1-i2==j1-j2;

    if(i1>=i2&&j1<=j2&&c1=='U'&&c2=='R')
        return i1-i2==j2-j1;

    if(i1<=i2&&j1<=j2&&c1=='D'&&c2=='R')
        return i2-i1==j2-j1;

    if(i1<=i2&&j1>=j2&&c1=='D'&&c2=='L')
        return i2-i1==j1-j2;

    return 0;
}

pair<char,char>calc(pair<char,char>ch,pair<int,int>p){
    if(p.first==1)ch.first='D';
    if(p.second==1)ch.second='R';

    if(p.first==n)ch.first='U';
    if(p.second==m)ch.second='L';

    return ch;
}

pair<pair<char,char>,pair<int,int>>conv(pair<char,char>ch,pair<int,int>p){
        if(ch.first=='U'&&ch.second=='L'){
            int mn=min(p.first-1,p.second-1);
            p.first-=mn,p.second-=mn;
        }

        if(ch.first=='U'&&ch.second=='R'){
            int mn=min(p.first-1,m-p.second);
            p.first-=mn,p.second+=mn;
        }

        if(ch.first=='D'&&ch.second=='L'){
            int mn=min(n-p.first,p.second-1);
            p.first+=mn,p.second-=mn;
        }

        if(ch.first=='D'&&ch.second=='R'){
            int mn=min(n-p.first,m-p.second);
            p.first+=mn,p.second+=mn;
        }

        ch=calc(ch,p);

        return{ch,p};
}

int main()
{
Ahmed_Sayed();
tt
int st1,st2,ans=0;
char st3,st4;
cin>>n>>m>>st1>>st2>>i2>>j2>>st3>>st4;
map<pair<int,int>,int>vis;

bool found=0;
while(vis[{st1,st2}]<2){
    if(ok(st3,st4,st1,st2)){found=1;break;}

    vis[{st1,st2}]++;
    ans++;

    auto p=conv({st3,st4},{st1,st2});
    st3=p.first.first,st4=p.first.second,
    st1=p.second.first,st2=p.second.second;
}

cout<<(found?ans:-1)<<'\n';}
}

{
Ahmed_Sayed();
tt
int n;cin>>n;
int x[n],ans=1e9;
for(auto&i:x)cin>>i;
sort(x,x+n);

for(int i=n-1;~i;i--){
    int l=0,r=i-1,m;
    while(l<=r){
        m=l+r>>1;

        (x[m]+x[m+1]<=x[i]?l=m+1:r=m-1);
    }
    ans=min(ans,int(l+(n-(upper_bound(x,x+n,x[i])-x))));
}

cout<<ans<<'\n';}
}
