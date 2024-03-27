class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0; // If k is less than or equal to 1, no subarray will have a product less than k
        
        int count = 0;
        int product = 1;
        int j = 0;

        for (int i = 0; i < nums.length; i++) {
            product *= nums[i]; // Expand the window(subarray) by multiplying the current element

            // Shrink the window(subarray) until the product is less than k
            while (product >= k) {
                product /= nums[j]; // Remove elements from the left end of the window(subarray)
                j++;
            }

            // Every time a valid subarray is found, add the count of subarrays to the result
            count += i - j + 1;
        }

        return count;
    }
}
