#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int Pre[(ll)2e5+5];
int Ok(int Rem,int One,int md){
    return max(Rem-md,One+Pre[md]);
}

int main()
{
Ahmed_Sayed();
tt
string s;cin>>s;

int AllZero=0,One=0;
for(int i=s.size()-1;~i;i--){
    if(s[i]=='0')Pre[++AllZero]=One;
    else One++;
}

One=0,s='*'+s;
int Zero=0,ans=1e9;
for(int i=0;i<s.size();i++){
    if(i)
        (s[i]=='0'?Zero++:One++);

    int Rem=AllZero-Zero,l=0,r=Rem-1,m;

    while(l<=r){
        m=l+r>>1;

        (Ok(Rem,One,m)>Ok(Rem,One,m+1)?l=m+1:r=m-1);
    }

    ans=min(ans,Ok(Rem,One,l));
}

cout<<ans<<'\n';}
}
