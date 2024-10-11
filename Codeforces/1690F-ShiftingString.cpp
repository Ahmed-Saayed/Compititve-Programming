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
ll n,lcm=1;
string s;cin>>n>>s;
int x[n],vis[n]{};
for(auto&i:x)cin>>i;

for(int i=0;i<n;i++){

        string t,tmp;
        
        ll o=i,c=1;
        while(!vis[o])
            t+=s[o],vis[o]=1,o=x[o]-1;

        tmp=t;
        t.insert(t.begin(),t.back()),
        t.pop_back();

        while(t!=tmp){
            t.insert(t.begin(),t.back()),
            t.pop_back(),c++;
        }

        lcm=lcm*c/__gcd(lcm,c);
}

cout<<lcm<<'\n';}
}