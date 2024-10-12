#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

const int N=2e5+5;
int sqr;
struct query{
    int l,r,idblk,idq;

    query(){}

    query(int _l,int _r,int _idq){
        l=_l,r=_r,idq=_idq,idblk=l/sqr;
    }

    bool operator<(const query&q)const{
        if(idblk!=q.idblk)return idblk<q.idblk;

        return r<q.r;
    }
};
const int N2=1e6+6;
query qu[N];
int n,q,x[N],fre[N2],FF[N],ret;
ll ans[N];
vector<int>adj[N2],prime(N2);

void add(int id){
    for(auto i:adj[x[id]]){
        int f=fre[i];

        if(f==ret)ret++;

        fre[i]++,
        FF[f+1]++,
        FF[f]--;
    }
}

void del(int id){
for(auto i:adj[x[id]]){
        int f=fre[i];

        if(f==ret&&FF[f]==1)ret--;

        fre[i]--,
        FF[f-1]++,
        FF[f]--;
    }
}

void MOs(){
    sort(qu,qu+q);

    int l=1,r=0;

    for(int i=0;i<q;i++){
        while(l<qu[i].l)del(l++);
        while(l>qu[i].l)add(--l);

        while(r<qu[i].r)add(++r);
        while(r>qu[i].r)del(r--);

        ans[qu[i].idq]=ret;
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<'\n';

    while(l<=r)del(l++);
}

int main()
{
Ahmed_Sayed();

for(int i=2;i<=1e6;i++){
    if(!prime[i]){
        for(int j=i;j<=1e6;j+=i)
            adj[j].push_back(i),prime[j]=1;
    }
}

tt
cin>>n>>q,sqr=sqrt(n)+5,ret=0;
for(int i=0;i<n;i++)cin>>x[i];

for(int i=0;i<q;i++){
    int l,r;cin>>l>>r;

    qu[i]=query(--l,--r,i);
}
MOs();}
}