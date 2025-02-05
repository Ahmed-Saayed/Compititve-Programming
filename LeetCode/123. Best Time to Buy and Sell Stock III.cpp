class Solution {
public:
    int maxProfit(vector<int>& x){
        int n = x.size(), suf[int(1e5) + 5]{},mx = 0;
        for(int i = n - 1 ;~i; i--){
            mx = max(mx, x[i]),
            suf[i] = max(suf[i + 1], mx - x[i]);
        }
        
        int mn = 1e9, ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, x[i] - mn + suf[i + 1]),
            mn = min(mn, x[i]);
        }

        return ans;
    }
};