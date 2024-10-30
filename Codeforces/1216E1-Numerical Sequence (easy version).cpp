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
ll ans=0,pre=0;
vector<ll>v{0};
for(int i=1;i<=100000;i++){
    int lg=log10(i);

    if(lg==log10(i))pre+=((ll)pow(10,lg)-(ll)pow(10,lg-1))*lg;

    ans+=(lg+1)*(i-(ll)pow(10,lg)+1)+pre;
    v.push_back(ans);
}

int q;cin>>q;
while(q--){
    int k;cin>>k;
    auto it=lower_bound(all(v),k);
    it--;
    k-=*it;
    
    char res;
    for(int i=1;k;i++){
        string t=to_string(i);

        if(t.size()<k)k-=t.size();
        else
        for(int j=0;j<t.size();j++){
            k--;

            if(!k){res=t[j];break;}
        }
    }

    cout<<res<<'\n';
}
}