int dp[10][1<<18][3];
int rec(int i,int mask,int take,vector<int>& nums, int numSlots){
    if(i>numSlots||mask==(1<<(int)nums.size())-1)return 0;

    int&ret=dp[i][mask][take];
    if(~ret)return ret;

    ret=rec(i+1,mask,0,nums,numSlots);

    for(int j=0;j<nums.size();j++){
        if(mask>>j&1||take==2)continue;

        ret=max(ret,(nums[j]&i)+rec(i,mask|(1<<j),take+1,nums,numSlots)),
        ret=max(ret,(nums[j]&i)+rec(i+1,mask|(1<<j),0,nums,numSlots));
    }

    return ret;
}
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(dp,-1,sizeof dp);
        return rec(1,0,0,nums,numSlots);
    }
};