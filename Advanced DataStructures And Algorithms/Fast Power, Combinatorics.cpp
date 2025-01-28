#define ll long long
ll mod=1e9+7;				//3428. Maximum and Minimum Sums of at Most Size K Subsequences
ll fp(ll x, ll k){
	ll ret = 1;
	x%=mod;
	while (k){
		if (k & 1) ret = (ret%mod*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret%mod;
}

const ll N=2e5+5;
ll fact[N+1],inv[N+1];
void pre(){
    fact[0]=inv[0]=1;
    for(ll i=1;i<=N;i++){
        fact[i] = fact[i-1] * i % mod;
        inv[i]=fp(fact[i],mod-2);
    }
}

ll fix(ll x){return (x%mod+mod)%mod;}

ll ncr(ll n,ll r){		
      if(r>n)return 0;
      return (fact[n]*inv[r])%mod*inv[n-r]%mod;
}
bool p;
class Solution {
public:
    int minMaxSums(vector<int>& x, int k) {
        if(!p)p=1,pre();
        
        sort(x.begin(),x.end());
        ll ans=0,n=x.size();
        for(auto i:x)ans=fix(ans+i*2);

        if(k==1)return ans;

        for(int i=0;i<n-1;i++)
            for(int j=1;j<k;j++)ans=fix(ans+ncr(n-1-i,j)*x[i]);

        for(int i=n-1;i;i--)
            for(int j=1;j<k;j++)ans=fix(ans+ncr(i,j)*x[i]);

        return ans;
    }
};