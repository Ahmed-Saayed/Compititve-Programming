#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct st{
    int ans,l,r;
};

const int N=1e5;
int n,id;
string s;
st seg[N*4];

st merge(st x,st y){
    st ret;

    int mn=min(x.l,y.r);
    ret.ans=x.ans+y.ans+mn;
    ret.l=x.l+y.l-mn;
    ret.r=x.r+y.r-mn;

    return ret;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        if(s[l]=='(')
            seg[node].l=1,seg[node].r=0;
        else
            seg[node].l=0,seg[node].r=1;

        return;
    }

    int m=(l+r)/2;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=merge(seg[node*2],seg[node*2+1]);
}

void up(int node=1,int l=1,int r=n){
    if(l>id||r<id)return;
    if(l==r){
        if(s[l]=='(')
            seg[node].l=0,seg[node].r=1,s[l]=')';
        else
            seg[node].l=1,seg[node].r=0,s[l]='(';

        return;
    }

    int m=(l+r)/2;
    up(node*2,l,m),
    up(node*2+1,m+1,r);

    seg[node]=merge(seg[node*2],seg[node*2+1]);
}

int main()
{
Ahmed_Sayed();
int cnt=1;
for(int i=1;i<=10;i++){
for(int j=1;j<N*4;j++)seg[j].ans=seg[j].l=seg[j].r=0;
cin>>n>>s;
s='*'+s;
bul();
cout<<"Test "<<cnt++<<":\n";

int q;cin>>q;
while(q--){
    cin>>id;
    if(!id)cout<<(seg[1].ans*2==n?"YES":"NO")<<'\n';
    else up();
}}
}
