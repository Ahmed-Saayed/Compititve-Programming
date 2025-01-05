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

const int N=306,mod=1e9+7,base=31;
ll pw[N];

void pre(){
    pw[0]=1;

    for(int i=1;i<N;i++){
        pw[i]=fix(base*pw[i-1],mod);
    }
}

struct SingleHashing{
    ll len,h,ha1,inv;
    vector<ll>pref,suf;

    SingleHashing(){
        len=h=0,
        inv=fp(base,mod-2,mod);
    }

    SingleHashing(string s){
        ha1=0;
        pref=suf=vector<ll>(s.size()+2);

        for(int i=1;i<s.size();i++){
            int ch=s[i]-'a'+1;

            ha1=fix(ha1*base+ch,mod),
            pref[i]=ha1;
        }

        ha1=0;
        for(int i=s.size()-1;i;i--){
            int ch=s[i]-'a'+1;

            ha1=fix(ha1*base+ch,mod),
            suf[i]=ha1;
        }
    }

    void push_b(char c){
        int ch=c-'a'+1;

        h=fix(h*base+ch,mod),
        len++;
    }

    void pop_b(char c){
        if(!len)return;

        int ch=c-'a'+1;

        h=fix(h-ch,mod);
        len--;
    }

    void push_f(char c){
        int ch=c-'a'+1;

        h=fix(h+pw[len]*ch,mod),
        len++;
    }

    void pop_f(char c){
        if(!len)return;

        int ch=c-'a'+1;

        h=fix(h-ch*pw[len-1],mod),
        len--;
    }

    ll get(){
        return h;
    }

    ll GetPre(int l,int r){
        ll ret=pref[r];

        ret=fix(ret-pref[l-1]*pw[r-l+1],mod);
        return ret;
    }

    ll GetSuf(int l,int r){
        ll ret=suf[l];

        ret=fix(ret-suf[r+1]*pw[r-l+1],mod);
        return ret;
    }
};

    class Solution {
    public:
        Solution(){
            pre();
        }
        vector<vector<int>> palindromePairs(vector<string>& x) {


            int n=x.size();

            vector<SingleHashing>h(n);
            for(int i=0;i<n;i++)
                if(x[i].size())h[i]= SingleHashing('*'+x[i]);

            vector<vector<int>>ans;

            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                        if(i==j)continue;

                        int sz1=x[i].size(),sz2=x[j].size(),odd=(max(sz1,sz2)-min(sz1,sz2))%2,md=(max(sz1,sz2)-min(sz1,sz2))>>1;

                        if(!sz1||!sz2){
                            if(!sz1&&!sz2)
                                ans.push_back({i,j});

                            else if(!sz1&&(!md||h[j].GetPre(1,md)==h[j].GetSuf(md+1+odd,sz2)))
                                ans.push_back({i,j});

                            else if(!sz2&&(!md||h[i].GetPre(1,md)==h[i].GetSuf(md+1+odd,sz1)))
                                ans.push_back({i,j});
                        }

                        else if(sz1==sz2&&h[i].GetPre(1,sz1)==h[j].GetSuf(1,sz2))
                            ans.push_back({i,j});

                        else if(sz1>sz2&&h[i].GetPre(1,sz2)==h[j].GetSuf(1,sz2)&&(!md||h[i].GetPre(sz2+1,sz2+md)==h[i].GetSuf(sz2+md+1+odd,sz1)))
                            ans.push_back({i,j});

                        else if(sz1<sz2&&h[i].GetPre(1,sz1)==h[j].GetSuf(sz2-sz1+1,sz2)&&(!md||h[j].GetPre(1,md)==h[j].GetSuf(md+1+odd,sz2-sz1)))
                            ans.push_back({i,j});
                }

                return ans;
        }
    };
