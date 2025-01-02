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
int n,m,a,b;cin>>n>>m>>a>>b;
if(a*n!=b*m){
    cout<<"NO\n";continue;
}
cout<<"YES\n";

int d;
for(int i=1;i<m;i++)
    if(i*n%m==0)d=i;

vector<string>ans;
ans.push_back(string(a,'1')+string(m-a,'0'));

for(int i=1;i<n;i++){
    string tmp=ans.back();

    for(int i=0;i<d;i++)
        tmp.insert(tmp.begin(),tmp.back()),tmp.pop_back();

    ans.push_back(tmp);
}

for(auto i:ans)
    cout<<i<<'\n';
nn;}
}
