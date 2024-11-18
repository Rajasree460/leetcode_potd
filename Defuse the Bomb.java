class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] decrypted = new int[n];

        // If k is zero, every element should be replaced by 0
        if (k == 0) {
            return decrypted; // Since the array is initialized with zeros by default
        }

        // Loop through each element in the code array
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // If k is positive, sum the next k elements
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n]; // Use modulo for circular indexing
                }
            } 
            // If k is negative, sum the previous k elements
            else {
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n]; // Use modulo for circular indexing
                }
            }

            // Store the calculated sum in the decrypted array
            decrypted[i] = sum;
        }

        // Return the decrypted array
        return decrypted;
    }
}
