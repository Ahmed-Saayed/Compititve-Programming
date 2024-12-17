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
int N=1e7;
vector<int>ans(N+1),sm(N+1);
for(int i=1;i<=N;i++){
    sm[i]+=i;
    if(sm[i]<=N&&!ans[sm[i]])
        ans[sm[i]]=i;

    for(int j=i*2;j<=N;j+=i)sm[j]+=i;
}

tt
int n;cin>>n;
cout<<(!ans[n]?-1:ans[n])<<'\n';
}
}
