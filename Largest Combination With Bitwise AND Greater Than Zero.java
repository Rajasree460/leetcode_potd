class Solution {
    public int largestCombination(int[] candidates) {
          int maxCount = 0;
  // Iterate over each bit position (assuming 32-bit integers)
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;
            for (int num : candidates) {
                // Check if the current bit is set in num
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }
            // Update maxCount with the maximum number of candidates having this bit set
            maxCount = Math.max(maxCount, count);
        }
        
        return maxCount;  
    }
}
