class Solution {
    public int minNumberOperations(int[] target) {
        int ans = target[0]; // start with first element
        for (int i = 1; i < target.length; i++) {
            // add increase only when current > previous
            if (target[i] > target[i - 1]) {
                ans += target[i] - target[i - 1];
            }
        }
        return ans; // total operations
    }
}
