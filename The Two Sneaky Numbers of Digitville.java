public class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length - 2;
        int z = nums[n] ^ nums[n + 1];
        for (int i = 0; i < n; i++) {
            z ^= i ^ nums[i];
        }

        int b = (z == 0) ? 0 : 31 - Integer.numberOfLeadingZeros(z);

        int[] ans = new int[2];
        for (int i = 0; i < n; i++) {
            ans[(i >> b) & 1] ^= i;
            ans[(nums[i] >>> b) & 1] ^= nums[i];
        }
        ans[(nums[n] >>> b) & 1] ^= nums[n];
        ans[(nums[n + 1] >>> b) & 1] ^= nums[n + 1];

        return ans;
    }
}
