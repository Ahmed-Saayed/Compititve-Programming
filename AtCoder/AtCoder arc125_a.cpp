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
int n,m;cin>>n>>m;
int x[n],y[m],fre1[2]{},fre2[2]{};
for(auto&i:x)cin>>i,fre1[i]++;
for(auto&i:y)cin>>i,fre2[i]++;

if((fre2[1]&&!fre1[1])||(fre2[0]&&!fre1[0]))
    cout<<-1;

else if(!fre2[0]||!fre2[1]){
    int id=1e9;
    for(int i=n-1;~i;i--)
        if(x[i]==y[0])id=min(id,n-i);

    for(int i=0;i<n;i++)
        if(x[i]==y[0])id=min(id,i);

    cout<<m+id;
}

else{
    int c=0,id=1e9;
    for(int i=n-1;~i;i--)
        if(x[i]!=x[0])id=min(id,n-i);

    for(int i=0;i<n;i++)
        if(x[i]!=x[0])id=min(id,i);

    for(int i=0;i<m-1;i++)
        if(y[i]!=y[i+1])c++;

    cout<<m+c+id-(x[0]==y[0]);
}
}
