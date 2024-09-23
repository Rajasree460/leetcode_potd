class Solution {
    public int minExtraChar(String s, String[] d) {
        Set<String> dict = new HashSet<>();
        for (String word : d) {
            dict.add(word);
        }
        int[] dp = new int[s.length() + 1];
        for (int i = 0; i <= s.length(); i++) {
            dp[i] = s.length(); 
        }
        dp[0] = 0; 
        for (int i = 1; i <= s.length(); i++) {
            dp[i] = dp[i - 1] + 1;  
            for (int j = 0; j < i; j++) {
                if (dict.contains(s.substring(j, i))) 
                    dp[i] = Math.min(dp[i], dp[j]);  
            }
        }
        return dp[s.length()]; 
    }
}
