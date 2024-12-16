    class Solution {
    public:
        int minKBitFlips(vector<int>& x, int k) {
            int n=x.size(),ans=0;
            vector<int>pre(n+2);

            for(int i=0;i<n;i++){
                if(i)pre[i]+=pre[i-1];

                if(pre[i]%2)x[i]=!x[i];

                if(!x[i]&&i+k-1>=n)return -1;

                if(!x[i])
                    x[i]=1,ans++,pre[i]++,pre[min(i+k,n)]--;
            }

            if(count(x.begin(),x.end(),0))ans=-1;

            return ans;
        }
    };