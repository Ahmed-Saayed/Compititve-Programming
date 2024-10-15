#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e6+1;
string s;
array<ll,3>seg[N*4];
ll n,lef,righ;

array<ll,3>merge(const array<ll,3>&l,const array<ll,3>&r){
    int o=min(l[0],r[1]);

    array<ll,3>ret;
    ret[2]=l[2]+r[2]+o;
    ret[0]=l[0]+r[0]-o;
    ret[1]=l[1]+r[1]-o;

    return ret;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node][s[l]==')']++;
        return;
    }

    int m=(l+r)/2;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=merge(seg[node*2],seg[node*2+1]);
}

array<ll,3>get(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return {};
    if(l>=lef&&r<=righ)return seg[node];

    int m=(l+r)/2;
    return merge(get(node*2,l,m),get(node*2+1,m+1,r));
}

int main()
{
Ahmed_Sayed();
cin>>s;
n=s.size();
s='*'+s;
bul();

int q;cin>>q;
while(q--){
    cin>>lef>>righ;
    cout<<get()[2]*2<<'\n';
}
}