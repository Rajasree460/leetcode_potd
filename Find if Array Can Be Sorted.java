class Solution {
    public boolean canSortArray(int[] nums) {
        int bitCount = Integer.bitCount(nums[0]);
        int prevMax = -1;
        int curMax = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (Integer.bitCount(nums[i]) != bitCount) {
                bitCount = Integer.bitCount(nums[i]);
                prevMax = Math.max(curMax, prevMax);
                curMax = nums[i];
            } else {
                curMax = Math.max(curMax, nums[i]);
            }
            if (prevMax != -1 && nums[i] < prevMax)
                return false;
        }
        return true;
    }
}
