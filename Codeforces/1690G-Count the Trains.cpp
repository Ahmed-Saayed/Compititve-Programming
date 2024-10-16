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
int n,m;cin>>n>>m;
int x[n],prev=2e9;
set<int>s;

for(int i=0;i<n;i++){
    cin>>x[i];
    if(x[i]<prev)
        prev=x[i],s.insert(i);
}

while(m--){
    int id,val;cin>>id>>val,id--;
    x[id]-=val;

    auto it=s.upper_bound(id);
    while(it!=s.end()&&x[id]<=x[*it])
        it=s.erase(it);

    it--;
    if(x[id]<x[*it])s.insert(id);

    cout<<s.size()<<' ';
}
nn;}
}
