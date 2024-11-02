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
vector<pair<int,int>>ans{{n-1,n},{n,n}};
for(int i=1;ans.size()<n;i++)ans.push_back({i,i});

for(auto[a,b]:ans)cout<<a<<' '<<b<<'\n';
nn;}
}
