class Solution {
    public double largestTriangleArea(int[][] points) {
        // step 1 - store maximum area in `maxArea`
        double maxArea = 0.0;

        // step 2 - generate all possible combinations of 3 points using three nested loops
        int n = points.length;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // extract points
                    int x1 = points[i][0];
                    int x2 = points[j][0];
                    int y1 = points[i][1];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    // step 3 - calculate area using cross product formula
                    // formula: Area = 0.5 * |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
                    double area = 0.5 * Math.abs(
                            x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
                        );

                    // step 4 - update maximum area
                    maxArea = Math.max(maxArea, area);
                }
            }
        }

        // step 5 - return maximum area of triangle
        return maxArea;
    }
}
