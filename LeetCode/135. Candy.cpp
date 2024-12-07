class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>v(n,1),pre(n),suf(n);

        int c=1;
        for(int i=0;i<n;i++){
            if(i){
                if(ratings[i]>ratings[i-1])c++;
                else c=1;
            }

            pre[i] = c;
        }

        c=1;

        for(int i=n-1;~i;i--){
            if(i+1!=n){
                if(ratings[i]>ratings[i+1])c++;
                else c=1;
            }

            suf[i] = c;
        }

        int ans=0;
        for(int i=0;i<n;i++)
            ans+=max(pre[i],suf[i]);

        return ans;
    }
};