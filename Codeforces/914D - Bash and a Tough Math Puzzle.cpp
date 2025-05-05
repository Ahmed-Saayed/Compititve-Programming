#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=5e5+5;
int n,x[N],seg[N*4];
void build(int node,int l,int r){
    if(l==r){
        seg[node]=x[l];
        return;
    }

    int m=l+r>>1;
    build(node*2,l,m),
    build(node*2+1,m+1,r);

    seg[node]=__gcd(seg[node*2],seg[node*2+1]);
}

int c;
void get(int node,int l,int r,int lef,int righ,int val){
    if(l>righ||r<lef||c>1||__gcd(seg[node],val)==val)
        return;
    if(l==r){
        c++;
        return;
    }

    int m=l+r>>1;
    get(node*2,l,m,lef,righ,val),
    get(node*2+1,m+1,r,lef,righ,val);
}

void update(int node,int l,int r,int id,int val){
    if(l>id||r<id)return;
    if(l==r){
        seg[node]=val;
        return;
    }

    int m=l+r>>1;
    update(node*2,l,m,id,val),
    update(node*2+1,m+1,r,id,val);

    seg[node]=__gcd(seg[node*2],seg[node*2+1]);
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=1;i<=n;i++)cin>>x[i];
build(1,1,n);

int q;cin>>q;
while(q--){
    int type;cin>>type;
    if(type==1){
        int l,r,val;cin>>l>>r>>val;

        c=0;
        get(1,1,n,l,r,val);
        cout<<(c>1?"NO":"YES")<<'\n';
    }
    else{
        int id,val;cin>>id>>val;
        update(1,1,n,id,val);
    }
}
}
