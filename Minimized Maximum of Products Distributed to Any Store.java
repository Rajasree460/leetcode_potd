class Solution {
    public boolean isPossible(int x, int[] quantities, int n) {
        double sum = 0;
        for (int u : quantities) {
            sum += Math.ceil((double) u / x);
        }
        return sum > n;
    }

    public int minimizedMaximum(int n, int[] quantities) {
        int left = 1, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isPossible(mid, quantities, n))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
}
