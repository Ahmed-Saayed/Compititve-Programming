#define ll long long
#define all(v) (v).begin(),(v).end()

ll mod = 1e9 + 7;
ll fp(ll x, ll k){
	ll ret = 1;
	x %= mod;
	while (k){
		if (k & 1) ret = (ret%mod*x) % mod;
		k >>= 1; x = (x * x) % mod;
	}
	return ret % mod;
}

const ll N = 2e5 + 5;
ll fact[N + 1], inv[N + 1];
void pre(int n){
    fact[0] = inv[0] = 1;
    for(ll i = 1; i <= n;i++){
        fact[i] = fact[i-1] * i % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll fix(ll x){return (x % mod + mod) % mod;}

ll ncr(ll n, ll r){
      if(r > n)return 0;
      return (fact[n] * inv[r]) % mod * inv[n - r] % mod;
}

ll calc(ll sm, ll sz, ll rem){
    return sm - (sz * rem);
}

bool p;
class Solution {
public:
    int distanceSum(int m, int n, int k) {
    if(!p) p = 1, pre(N);       // Preproccess
    
    vector<ll>v1, v2;
    for(int i = 1; i <= n;i++)
        for(int j = 1 ;j <= m;j++)
            v1.push_back(i), v2.push_back(j);

    sort(all(v1)),sort(all(v2));
    ll ans = 0, sz = n * m , f = ncr(sz - 2 , k - 2) ,sm1 = 0 ,sm2 = 0;
    for(auto i : v1)sm1 += i;
    for(auto i : v2)sm2 += i;

    for(int i = 0 ; i < v1.size();i++){          // for rows
        sm1 -= v1[i],
        ans = (ans + calc(sm1, v1.size() - i - 1 ,v1[i]) * f) % mod;
    }
    
    for(int i = 0 ; i < v2.size(); i++){        // for columns 
        sm2 -= v2[i],
        ans = (ans + calc(sm2, v2.size() - i - 1 ,v2[i]) * f) % mod;
    }
    return ans;
    }
};