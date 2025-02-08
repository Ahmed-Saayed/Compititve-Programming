class Solution {
public:
    int maximalRectangle(vector<vector<char>>& x)  {
        int n = x.size(), m = x[0].size();
        int suf[n][m];

        for(int i = 0; i < n ;i++){
            int o = m;
            for(int j = m - 1; ~j ;j--){
                if(x[i][j] == '0') o = j;

                suf[i][j] = o;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0 ;j < m; j++){
                int o = suf[i][j];
                for(int k = i; k < n ;k++){
                    o = min(o, suf[k][j]);
                    ans = max(ans, (o - j) * (k - i + 1));
                }
            }
        }
        return ans;
    }
};