#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+1;
int n,x[N],seg[N*4],lef,righ,id,val;
void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node]=x[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node]=min(seg[node*2],seg[node*2+1]);
}

ll get(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return 1e18;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return min(get(node*2,l,m),get(node*2+1,m+1,r));
}

void up(int node=1,int l=1,int r=n){
    if(l>id||r<id)return;
    if(l==r){
        seg[node]=val;
        return;
    }

    int m=l+r>>1;
    up(node*2,l,m),
    up(node*2+1,m+1,r);

    seg[node]=min(seg[node*2],seg[node*2+1]);
}

int main()
{
Ahmed_Sayed();
int q;cin>>n>>q;
for(int i=1;i<=n;i++)cin>>x[i];
bul();

while(q--){
    vector<ll>v;
    string s,t;cin>>s;
    bool p=0;
    for(auto i:s){
        if(p){
            if(i>='0'&&i<='9')t+=i;else v.push_back(stoll(t)),t="";
        }
        if(i=='(')p=1;
    }

    if(s[0]=='q')lef=v[0],righ=v[1],cout<<get()<<'\n';
    else{
        ll o=x[v[0]];
        for(int i=0;i<v.size()-1;i++){
            id=v[i],val=x[v[i+1]],x[id]=val,up();
        }
        id=v.back(),val=o,x[id]=val,up();
    }
}
}
//