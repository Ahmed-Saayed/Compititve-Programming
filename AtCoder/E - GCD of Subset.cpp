#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){					//E - GCD of Subset contests/abc393
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e6+5;
vector<int>adj[N];
int main()
{
Ahmed_Sayed();
int n,k;cin>>n>>k;

vector<int>nums(N),fre(N),x(n);
for(int i=0;i<n;i++){
    cin>>x[i],fre[x[i]]++;
}

for(int i=1;i<N;i++)
    for(int j=i;j<N;j+=i)
        nums[i]+=fre[j],adj[j].push_back(i);


for(int i=0;i<n;i++){
    int ans=1;
    for(int j=adj[x[i]].size()-1;~j;j--)
        if(nums[adj[x[i]][j]]>=k){
            ans=adj[x[i]][j];break;
        }

    cout<<ans<<'\n';
}
}
