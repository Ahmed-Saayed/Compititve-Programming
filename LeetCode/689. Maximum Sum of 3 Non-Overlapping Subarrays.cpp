#define ll long long

vector<int>pre,ans;
ll n,k,dp[(ll)2e4+5][4];
ll rec(int i=1,int cnt=3){
    if(i==n+1||!cnt)return cnt*-1e9;

    ll&ret=dp[i][cnt];
    if(~ret)return ret;
    
    ret=0;

    if(n-i+1>=k)
        ret=pre[i+k-1]-pre[i-1]+rec(i+k,cnt-1);

    return ret=max(ret,rec(i+1,cnt));
}

void bul(int i=1,int cnt=3){
    if(i==n+1||!cnt)return;

    ll best=rec(i,cnt);

    if(n-i+1>=k&&best==pre[i+k-1]-pre[i-1]+rec(i+k,cnt-1)){
        ans.push_back(i-1);
        return bul(i+k,cnt-1);
    }

    bul(i+1,cnt);
}

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int o) {
        pre=nums,n=pre.size(),k=o,ans.clear();

        pre.insert(pre.begin()+0,0);
        for(int i=1;i<=n;i++)
            pre[i]+=pre[i-1],fill(dp[i],dp[i]+4,-1);
        
        bul();

        return ans;
    }
};