class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        Set<Character> set=new HashSet<>();
        for(char c:allowed.toCharArray()){
            set.add(c);
        }

        int count=0;
        for(String word:words){
            int flag=0;
            for(char c:word.toCharArray()){
                if(!set.contains(c)){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                count+=1;
            }    
        }
        return count;
    }
}
