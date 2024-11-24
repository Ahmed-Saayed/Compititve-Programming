class Solution {
public:
    vector<int>x;
    int kk,dp[101][101][101];
    int rec(int i, int op, int op2){
        if(i == x.size())return 0;
        
        int & ret = dp[i][op][op2];
        if(~ret)return ret;
        
         ret = x[i] + rec(i + 1, op, op2);

        if(op)
            ret = min(ret, (x[i] + 1) / 2 + rec(i + 1, op - 1, op2));
        
        if(op2 && x[i] >= kk){
            ret=min(ret, x[i] - kk + rec(i + 1, op, op2 - 1)); 

            if(op && (x[i] + 1) / 2 - kk >= 0)
                ret = min(ret, (x[i] + 1) / 2 - kk + rec(i+1,op-1,op2-1)); 
            
            if(op && (x[i] - kk + 1) / 2 >= 0)
                ret = min(ret, (x[i] - kk + 1) / 2 + rec(i + 1,op - 1,op2 - 1)); 
            
        }
        return ret;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        x = nums, kk = k,
        memset(dp, -1, sizeof dp);

        return rec(0, op1, op2);
    }
};