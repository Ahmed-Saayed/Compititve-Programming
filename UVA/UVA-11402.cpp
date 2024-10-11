#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1024005;
int n,seg[N*4],lazy[N*4],lef,righ,val;
char c;
string s;

void push(int node,int l,int r){
    if(!lazy[node])return;

    if(lazy[node]!=3)seg[node]=(r-l+1)*(lazy[node]-1);
    else seg[node]=r-l+1-seg[node];

    if(l!=r){
        if(lazy[node]!=3)lazy[node*2]=lazy[node*2+1]=lazy[node];
        else lazy[node*2]^=lazy[node],lazy[node*2+1]^=lazy[node];
    }
    lazy[node]=0;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node]=s[l]-'0';
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=seg[node*2]+seg[node*2+1];
}

ll get(int node=1,int l=1,int r=n){
    push(node,l,r);

    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return get(node*2,l,m)+get(node*2+1,m+1,r);
}

void up(int node=1,int l=1,int r=n){
    push(node,l,r);

    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        lazy[node]=val;
        push(node,l,r);

        return;
    }

    int m=l+r>>1;
    up(node*2,l,m),
    up(node*2+1,m+1,r);

    seg[node]=seg[node*2]+seg[node*2+1];
}

int id=1;
int main()
{
Ahmed_Sayed();
tt
int cnt=1;
cout<<"Case "<<id++<<":\n";
s="";
ll m;cin>>m;
while(m--){
    ll t;string o;cin>>t>>o;
    while(t--)s+=o;
}

n=s.size();
for(int i=0;i<n*4;i++)seg[i]=lazy[i]=0;

s='*'+s;
bul();

int q;cin>>q;
while(q--){
    cin>>c>>lef>>righ,lef++,righ++;
    if(c=='S')cout<<'Q'<<cnt++<<": "<<get()<<'\n';
    else{
        if(c=='E')val=1;
        if(c=='F')val=2;
        if(c=='I')val=3;
        up();
    }
}}
}
//