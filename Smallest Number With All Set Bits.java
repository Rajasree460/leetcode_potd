public class Solution {
    public static int smallestNumber(int n) {
        int count = 0;
        int weight = 1;

        while (weight <= n) {
            weight *= 2;
            count++;
        }

        return (1 << count) - 1;
    }
}
