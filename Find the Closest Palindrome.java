class Solution {
    public String nearestPalindromic(String n) {
        int len = n.length();
        int i;
        // Determine the middle point of the number
        if (len % 2 == 0) {
            i = len / 2 - 1;  // For even length, the middle ends one place left
        } else {
            i = len / 2;  // For odd length, the middle is the center
        }
        
        // Extract the first half of the number as an integer
        long firsthalf = Long.valueOf(n.substring(0, i + 1));
        
        // List to store all possible palindrome candidates
        List<Long> posibility = new ArrayList<>();
        // Generate palindrome by mirroring the first half
        posibility.add(halftopalindrome(firsthalf, len % 2 == 0));
        // Generate palindrome by mirroring the first half - 1
        posibility.add(halftopalindrome(firsthalf - 1, len % 2 == 0));
        // Generate palindrome by mirroring the first half + 1
        posibility.add(halftopalindrome(firsthalf + 1, len % 2 == 0));
        // Edge case: smallest palindrome with one less digit
        posibility.add((long) Math.pow(10, len - 1) - 1);
        // Edge case: smallest palindrome with one more digit
        posibility.add((long) Math.pow(10, len) + 1);
        
        long diff = Long.MAX_VALUE;  // Initialize minimum difference
        long res = 0;  // Result to store the closest palindrome
        long num = Long.valueOf(n);  // Convert the input number to long for comparison
        
        // Find the palindrome with the minimum absolute difference
        for (long pos : posibility) {
            if (num == pos) {
                continue;  // Skip if it's the same as the input number
            }
            if (Math.abs(pos - num) < diff) {
                diff = Math.abs(pos - num);  // Update the minimum difference
                res = pos;  // Update the result with the closest palindrome
            } else if (Math.abs(pos - num) == diff) {
                res = Math.min(res, pos);  // Handle tie cases, choose the smaller one
            }
        }
        return "" + res;  // Convert the result to string and return
    }

    // Helper function to generate a palindrome from the half
    long halftopalindrome(long firsthalf, boolean even) {
        long res = firsthalf;
        if (!even) {
            firsthalf /= 10;  // Remove the middle digit if the length is odd
        }
        while (firsthalf > 0) {
            res = res * 10 + (firsthalf % 10);  // Mirror the first half
            firsthalf /= 10;
        }
        return res;  // Return the complete palindrome
    }
}
