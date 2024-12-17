int dp[(int)1001];
int rec(int i,int d,int n,vector<int>& arr){

    int&ret=dp[i];
    if(~ret)return ret;

    ret=1;
    for(int j=i+1;j<=min(n-1,i+d)&&arr[j]<arr[i];j++)
        ret=max(ret,1+rec(j,d,n,arr));

    for(int j=i-1;j>=max(0,i-d)&&arr[j]<arr[i];j--)
        ret=max(ret,1+rec(j,d,n,arr));

    return ret;
}
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size(),ans=1;
        fill(dp,dp+n,-1);


        for(int i=0;i<n;i++)
            ans=max(ans,rec(i,d,n,arr));

        return ans;
    }
};