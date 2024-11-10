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
int n,ans=0;
string s,t;cin>>n>>s>>t;
for(int i=0;i<n/2;i++){
    if((s[i]==t[i]&&s[n-1-i]==t[n-1-i])||(s[i]==t[n-1-i]&&s[n-1-i]==t[i])||(s[i]==s[n-1-i]&&t[i]==t[n-1-i]))continue;

    if(s[i]==t[i]||s[i]==t[n-1-i]||s[n-1-i]==t[i]||s[n-1-i]==t[n-1-i]||t[i]==t[n-1-i])ans++;
    else ans+=2;
}

cout<<ans+(n%2&&s[n/2]!=t[n/2]);
}
