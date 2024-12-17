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
int n,ans=1;cin>>n;
int x[n+1],fre[n+1]{};
set<int>s;
for(int i=1;i<=n;i++)
    cin>>x[i],fre[x[i]]++;

for(int i=1;i<=n;i++)
    if(!fre[i])s.insert(i);

while(s.size()){
    ans++;
    set<int>q;

    for(auto i:s){
        fre[x[i]]--;

        if(!fre[x[i]])q.insert(x[i]);
    }

    s=q;
}

cout<<++ans<<'\n';}
}
