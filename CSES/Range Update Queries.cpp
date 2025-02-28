#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct st{
    ll val,lazy;
};


const int N=2e5+5;
int n,x[N];
st seg[N*4];

void push(int node,int l,int r){
    if(l!=r){
        seg[node*2].lazy+=seg[node].lazy,
        seg[node*2+1].lazy+=seg[node].lazy;
    }
    else
        seg[node].val+=seg[node].lazy;

    seg[node].lazy=0;
}

void bul(int node,int l,int r){
    if(l==r){
        seg[node].val=x[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);
}

ll get(int node,int l,int r,int id){
    push(node,l,r);

    if(l>id||r<id)return 0;
    if(l==r)return seg[node].val;

    int m=l+r>>1;
    return  get(node*2,l,m,id)+get(node*2+1,m+1,r,id);
}

void up(int node,int l,int r,int lef,int righ,int val){
    push(node,l,r);

    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        seg[node].lazy+=val;
        push(node,l,r);

        return;
    }

    int m=l+r>>1;
    up(node*2,l,m,lef,righ,val),
    up(node*2+1,m+1,r,lef,righ,val);
}


int main()
{
Ahmed_Sayed();
int q;cin>>n>>q;
for(int i=1;i<=n;i++)cin>>x[i];

bul(1,1,n);
while(q--){
    int o;cin>>o;

    if(o==1){
        int l,r,val;cin>>l>>r>>val;
        up(1,1,n,l,r,val);
    }
    else{
        int id;cin>>id;
        cout<<get(1,1,n,id)<<'\n';
    }
}
}
