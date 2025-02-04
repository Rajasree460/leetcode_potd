class Solution {
    public int maxAscendingSum(int[] nums) {
        int cs=nums[0], ans=nums[0];  //ans= prv sum
        for(int i=1;i<nums.length;i++){
            if(nums[i]>nums[i-1]){
                cs=cs+nums[i];
            }else{
                cs=nums[i];
            }
            ans=Math.max(ans,cs);
        }
        return ans;
    }
}
