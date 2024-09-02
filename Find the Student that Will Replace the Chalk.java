class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        int sum = 0;
        //Compute Total Chalk Usage
        for(int i = 0; i < chalk.length; i++) {  
            sum += chalk[i];
            if (sum > k) return i;
        }
 
        //Compute Remaining Chalk
        k %= sum;
        

        //Determine Which Student Uses the Last Piece of Chalk
        for(int i = 0; i < chalk.length; i++) {
            if(chalk[i] > k) return i;
             else k -= chalk[i];
        }
        
        return 1;  //default return value
    }
}
