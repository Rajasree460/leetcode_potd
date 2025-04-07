class Solution {
    public boolean canPartition(int[] nums) {
        int totalSum=0;
        for(int i=0;i<nums.length;i++){
            totalSum+=nums[i];
        }

        if(totalSum%2!=0){
            return false;
        }
        int targetSum=totalSum/2;
        boolean dp[]= new boolean[targetSum+1]; //char array

        dp[0]=true; //as we always get sum 0, if we pick nothing
        for(int i=1;i<nums.length;i++){
            for(int currSum=targetSum; currSum>=nums[i]; currSum--){
                dp[currSum]=dp[currSum] || dp[currSum - nums[i]];

                if(dp[targetSum])    //ie if dp[11]==true,thatmeans all elems of dp are true, return true immediately
                return true;
            }
        }
       return dp[targetSum]; //either true or false
    }
}
