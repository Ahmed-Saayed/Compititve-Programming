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
ll n,id,id2=-1;cin>>n;
cout<<"? 1 "<<n<<endl;
cin>>id;

if(id!=n){
    cout<<"? "<<id<<' '<<n<<endl;
    cin>>id2;
}

if(id2==id){
    int l=id+1,r=n,m;
    while(l<=r){
        m=l+r>>1;

        cout<<"? "<<id<<' '<<m<<endl;
        cin>>id2;

        (id2!=id?l=m+1:r=m-1);
    }
    cout<<"! "<<l;
}
else{
    int l=1,r=id-1,m;
    while(l<=r){
        m=l+r>>1;

        cout<<"? "<<m<<' '<<id<<endl;
        cin>>id2;

        (id2!=id?r=m-1:l=m+1);
    }
    cout<<"! "<<r;
}
}
