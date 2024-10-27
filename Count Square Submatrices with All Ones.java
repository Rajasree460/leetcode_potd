public class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        int count = 0;
        
        // Fill the dp array and count squares
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    // If we're at the first row or column, only 1x1 square is possible
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // Check minimum of top, left, and top-left cells, then add 1
                        dp[i][j] = Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                    count += dp[i][j];
                }
            }
        }
        
        return count;
    }
}
