class Solution {
    // Method to find the binary complement of a given number
    public int findComplement(int num) {
        // Convert the integer 'num' to its binary string representation (decimal->binary)
        String str = Integer.toBinaryString(num);
        
        // Initialize an empty string to store the binary complement
        String res = "";
        
        // Loop through each character of the binary string
        for(int i = 0; i < str.length(); i++) {
            // If the current character is '0', append '1' to the result
            if(str.charAt(i) == '0') {
                res += '1';
            }
            // If the current character is '1', append '0' to the result
            else {
                res += '0';
            }
        }
        
        // Convert the resulting binary string back to an integer
        // Specify base 2 to indicate it's binary(binary->decimal)
        return Integer.parseInt(res, 2);
    }
}
