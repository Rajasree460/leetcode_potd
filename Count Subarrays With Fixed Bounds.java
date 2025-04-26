class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int badPos = -1, minPos = -1, maxPos = -1;
        long count = 0;
        for(int i = 0;i<nums.length;i++){
            if(nums[i] < minK || nums[i] > maxK){
                badPos = i;
            }
            if(nums[i]==minK)
             minPos = i;
            if(nums[i] == maxK)
              maxPos = i;
            
            int minValid = Math.min(minPos,maxPos);
            if(minValid > badPos)
              count += minValid-badPos;
        }
        return count;
    }
}
