#define ll long long
const int N=1e5+1;
vector<ll>adj(N);
class Solution {
public:
    ll mod=1e9+7;
    ll fp(ll x, ll k){
        ll ret = 1;
        x%=mod;
        while (k){
            if (k & 1) ret = (ret%mod*x) % mod;
            k >>= 1; x = (x*x) % mod;
        }
        return ret%mod;
    }
    ll fix(ll x){return (x%mod+mod)%mod;}

    void PreProcess(){
        for(int i=2;i<N;i++)
            if(!adj[i])
                for(int j=i;j<N;j+=i)
                    adj[j]++;
    }

    bool o=1;

    int maximumScore(vector<int>& nums, int k) {
            if(o)
                o=0,PreProcess();

            int n=nums.size();
            vector<int>pre(n),suf(n),x;

            for(auto i:nums)
                x.push_back(adj[i]);

            stack<int>st;
            for(int i=0;i<n;i++){
                while(st.size()&&x[i]>x[st.top()])
                    suf[st.top()]=i,st.pop();

                st.push(i);
            }

            while(st.size())
                suf[st.top()]=n,st.pop();

            for(int i=n-1;~i;i--){
                while(st.size()&&x[i]>=x[st.top()])
                    pre[st.top()]=i,st.pop();

                st.push(i);
            }

            while(st.size())
                pre[st.top()]=-1,st.pop();

            vector<pair<int,int>>v;
            for(int i=0;i<n;i++)
                v.push_back({nums[i],i});

            sort(v.begin(),v.end(),greater<>());

            ll ans=1;
            for(auto[a,b]:v){
                ll l=pre[b]+1,r=suf[b]-1;

                ll mn=min(1ll*k,(b-l+1)*(r-b+1));

                k-=mn,
                ans=fix(ans*fp(a,mn));
            }

        return ans;
    }
};