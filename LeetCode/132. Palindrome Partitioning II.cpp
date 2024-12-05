#define ll long long
ll fp(ll x, ll k,ll mod){
	ll ret = 1;
	x%=mod;
	while (k){
		if (k & 1) ret = (ret%mod*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret%mod;
}
ll fix(ll x,ll mod){return (x%mod+mod)%mod;}

const int N=1e6+5,mod=1e9+7,mod2=2e9+11,base=31,base2=37;
ll pw[N],pw2[N];

void pre(){
    pw[0]=pw2[0]=1;

    for(int i=1;i<N;i++){
        pw[i]=fix(base*pw[i-1],mod),
        pw2[i]=fix(base2*pw2[i-1],mod2);
    }
}

struct DoubleHashing{
    ll len,h,h2,ha1,ha2,inv,inv2;
    vector<pair<ll,ll>>pref,suf;

    DoubleHashing(){
        len=h=h2=0,
        inv=fp(base,mod-2,mod),inv2=fp(base2,mod2-2,mod2);
    }

    DoubleHashing(string s){
        ha1=ha2=0;
        pref=suf=vector<pair<ll,ll>>(s.size()+2);

        for(int i=1;i<s.size();i++){
            int ch=s[i]-'a'+1;

            ha1=fix(ha1*base+ch,mod),
            ha2=fix(ha2*base2+ch,mod2),
            pref[i]={ha1,ha2};
        }

        ha1=ha2=0;
        for(int i=s.size()-1;i;i--){
            int ch=s[i]-'a'+1;

            ha1=fix(ha1*base+ch,mod),
            ha2=fix(ha2*base2+ch,mod2),
            suf[i]={ha1,ha2};
        }
    }

    void push_b(char c){
        int ch=c-'a'+1;

        h=fix(h*base+ch,mod),
        h2=fix(h2*base2+ch,mod2),

        len++;
    }

    void pop_b(char c){
        if(!len)return;

        int ch=c-'a'+1;

        h=fix(h-ch,mod),
        h=fix(h*inv,mod),

        h2=fix(h2-ch,mod2),
        h2=fix(h2*inv2,mod2),

        len--;
    }

    void push_f(char c){
        int ch=c-'a'+1;

        h=fix(h+pw[len]*ch,mod),
        h2=fix(h2+pw2[len]*ch,mod2),

        len++;
    }

    void pop_f(char c){
        if(!len)return;

        int ch=c-'a'+1;

        h=fix(h-ch*pw[len-1],mod),
        h2=fix(h2-ch*pw2[len-1],mod2),

        len--;
    }

    pair<ll,ll>get(){
        return {h,h2};
    }

    pair<ll,ll>GetPre(int l,int r){
        pair<ll,ll>ret=pref[r];

        ret.first=fix(ret.first-pref[l-1].first*pw[r-l+1],mod);
        ret.second=fix(ret.second-pref[l-1].second*pw2[r-l+1],mod2);

        return ret;
    }

    pair<ll,ll>GetSuf(int l,int r){
        pair<ll,ll>ret=suf[l];

        ret.first=fix(ret.first-suf[r+1].first*pw[r-l+1],mod);
        ret.second=fix(ret.second-suf[r+1].second*pw2[r-l+1],mod2);

        return ret;
    }
};

vector<int>adj[3000];
int n,dp[3000];
int rec(int i=1){
    if(i==n)return 0;

    int&ret=dp[i];
    if(~ret)return ret;
    
    ret=1e9;

    for(auto j:adj[i])
        ret=min(ret,1+rec(j+1));

    return ret;
}

class Solution {
public:
    int minCut(string s) {
        pre(),memset(dp,-1,sizeof dp);
        
        s='*'+s,n=s.size();
        fill(adj,adj+s.size(),vector<int>());

        DoubleHashing h(s);
        for(int i=1;i<s.size();i++){
            adj[i].push_back(i);

            for(int j=i+1;j<s.size();j++){
                if((j-i+1)%2){
                    int m=(i+j)>>1;

                    if(h.GetPre(i,m-1)==h.GetSuf(m+1,j))
                        adj[i].push_back(j);
                }
                else{
                    int m=(i+j)>>1;

                    if(h.GetPre(i,m)==h.GetSuf(m+1,j))
                        adj[i].push_back(j);
                }
            }
        }

       return rec()-1;
    }
};
