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
 
query qu[N];
int n,q,x[N],vis[(ll)1e6+6],ret;
ll ans[N];
 
void add(int id){
    ret+=!vis[x[id]];
    vis[x[id]]++;
}
 
void del(int id){
    ret-=vis[x[id]]==1;
    vis[x[id]]--;
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
cin>>n>>q,sqr=sqrt(q+5);
 
int o=0;
map<int,int>mp;
for(int i=0;i<n;i++)
    cin>>x[i],mp[x[i]]=o++;
 
for(auto&i:x)i=mp[i];
 
for(int i=0;i<q;i++){
    int l,r;cin>>l>>r;
 
    qu[i]=query(--l,--r,i);
}
 
MOs();
}
