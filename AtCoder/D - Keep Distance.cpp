#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int n,m;
set<vector<int>>s;
void rec(int i,int val,vector<int>v){
    if(i==n){
        s.insert(v);
        return;
    }

    for(int j=val;j<=m-(n-i-1)*10;j++){
        v[i]=j,
        rec(i+1,j+10,v);
    }
}


int main()
{
Ahmed_Sayed();
cin>>n>>m;
rec(0,1,vector<int>(n));

cout<<s.size()<<'\n';
for(auto i:s){
    for(auto j:i)cout<<j<<' ';
    nn;
}
}
