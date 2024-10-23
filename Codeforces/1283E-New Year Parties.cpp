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
int n,mx=0,mn=0;cin>>n;
int x[n],on[n+5]{};

set<int>s;
for(int i=0;i<n;i++)
    cin>>x[i],s.insert(x[i]);

sort(x,x+n);

for(int i=0;i<n;i++){
    if(!on[x[i]-1])
        mx++,on[x[i]-1]=1;

    else if(!on[x[i]])
        mx++,on[x[i]]=1;

    else if(!on[x[i]+1])
        mx++,on[x[i]+1]=1;
}

while(s.size()){
    int o=*s.begin();

    s.erase(o),s.erase(o+1),s.erase(o+2);
    mn++;
}

cout<<mn<<' '<<mx;
}