public class Solution {
    public int WaysToSplitArray(int[] nums) {
        long ans = 0, sm1 = 0, sm2 = 0;
        foreach(var i in nums)sm2 += i;

        for(int i = 0 ;i < nums.Length - 1; i++){
            sm1 += nums[i];
            sm2 -= nums[i];

            ans += (sm1 >= sm2? 1 : 0);
        }      

        return (int)ans;
    }
}