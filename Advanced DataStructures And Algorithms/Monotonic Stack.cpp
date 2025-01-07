class Solution {
public:
    int largestRectangleArea(vector<int>& x) {		//84.Largest Rectangle in Histogram
        int n  = x.size();
        vector<int>pre(n,-1),suf(n,n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(st.size() && x[i] < x[st.top()])
                suf[st.top()] = i, st.pop();

            st.push(i);
        }

        for(int i=n-1;~i;i--){
            while(st.size() && x[i] < x[st.top()])
                pre[st.top()] = i, st.pop();

            st.push(i);
        }

        int ans=0;
        for(int i = 0; i< n; i++)
            ans=max(ans, (suf[i] - pre[i] - 1) * x[i]);

        return ans;
    }
};