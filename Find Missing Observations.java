class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int sum = 0;
        for (int roll : rolls) {
            sum += roll;
        }

        // missing
        int missing = mean * (n + rolls.length) - sum;
        if (missing < n || missing > 6 * n) {
            return new int[0];
        }

        int part = missing / n, rem = missing % n;
        int[] arr = new int[n];
        Arrays.fill(arr, part);
        for (int i = 0; i < rem; i++) {
            arr[i]++;
        }
        return arr;
    }
}
