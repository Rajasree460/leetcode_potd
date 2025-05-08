class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length, m = moveTime[0].length;
        int dx = 1, dy = 0;

        PriorityQueue<int[]> heap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        heap.add(new int[]{0, 0, 0, 1});

        Set<String> seen = new HashSet<>();
        seen.add("0,0");

        while (!heap.isEmpty()) {
            int[] current = heap.poll();
            int time = current[0], x = current[1], y = current[2], step = current[3];

            if (x == n - 1 && y == m - 1) return time;

            for (int i = 0; i < 4; i++) {
                int X = x + dx, Y = y + dy;
                int tempDx = dx, tempDy = dy;
                dx = -tempDy;
                dy = tempDx;

                String pos = X + "," + Y;
                if (onGrid(X, Y, n, m) && !seen.contains(pos)) {
                    int t = Math.max(time, moveTime[X][Y]) + step;
                    heap.add(new int[]{t, X, Y, 3 - step});
                    seen.add(pos);}
            }
        }
        return -1; // Return -1 if unreachable
    }
    private boolean onGrid(int x, int y, int n, int m) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
}
