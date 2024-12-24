#define ll long long
#define all(v) (v).begin(),(v).end()

struct DSU{
    vector<ll>par,sz;				//1998. GCD Sort of an Array
    ll sm,edges;

    DSU(){};

    DSU(ll n){
        sm=0,edges=n;
        par=sz=vector<ll>(n+1);
        for(int i=0;i<=n;i++)par[i]=i,sz[i]=1;
    }

    ll findlead(ll n){
        if(par[n]==n)return n;
        return par[n]=findlead(par[n]);
    }

    bool merge(ll x,ll y,ll c){
        x=findlead(x),y=findlead(y);
        if(x==y)return 0;

        sm+=c,edges--;
        if(sz[x]>=sz[y])sz[x]+=sz[y],par[y]=x;
        else sz[y]+=sz[x],par[x]=y;
        return 1;
}
};
DSU op;
class Solution {
public:
    void merge(int n){
        vector<int>primes;
        int o,n2=n;

        for(int i=2;i*i<=n;i++)
            while(n%i==0)primes.push_back(i),n/=i,o=i;

        if(n!=1)primes.push_back(n),o=n;

        for(int i=0;i<primes.size()-1;i++)
            op.merge(primes[i],primes[i+1],0);

        op.merge(n2,o,0);
    }

    bool gcdSort(vector<int>& nums) {
       op=DSU(1e5);

       for(auto i:nums)merge(i);

       auto v=nums;
       sort(v.begin(),v.end());

       for(int i=0;i<v.size();i++)
          if(op.findlead(v[i])!=op.findlead(nums[i]))return 0;
       
       return 1;
    }
};