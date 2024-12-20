class Solution {
public:
    int maximumScore(vector<int>& x, int k) {
        int n=x.size(),ans=0;
        vector<int>pre(n,-1),suf(n,n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(st.size()&&x[st.top()]>x[i])
                suf[st.top()]=i,st.pop();

            st.push(i);
        }

        while(st.size())st.pop();

        for(int i=n-1;~i;i--){
            while(st.size()&&x[st.top()]>x[i])
                pre[st.top()]=i,st.pop();

            st.push(i);
        }

        for(int i=0;i<n;i++)
            if(k>pre[i]&&k<suf[i])
                ans=max(ans,(suf[i]-pre[i]-1)*x[i]);

        return ans;
    }
};