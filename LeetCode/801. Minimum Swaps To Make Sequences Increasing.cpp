const int N=1e5+5;
int n,x[N],y[N],dp[N][2];
int rec(int i=0,int o=0){
    if(i==n)return 0;

    int&ret=dp[i][o];
    if(~ret)return ret;
    
    ret=1e9;

    if(!i)
        return ret=min(rec(i+1,0),1+rec(i+1,1));
        
    else{ 
        int a,b;
        if(!o)a=x[i-1],b=y[i-1];
        else  a=y[i-1],b=x[i-1];

        if(x[i]>a&&y[i]>b)
            ret=rec(i+1,0);

        if(y[i]>a&&x[i]>b)
            ret=min(ret,1+rec(i+1,1));
    }
    
    return ret;
}
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        for(int i=0;i<n;i++)
            x[i]=nums1[i],y[i]=nums2[i],dp[i][0]=dp[i][1]=-1;

        return rec();
    }
};