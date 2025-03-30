class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] lastIndex = new int[26];
        for(int i =0; i < s.length(); i++){
            lastIndex[s.charAt(i) - 'a'] = i;
        }
        List<Integer> result = new ArrayList<>();
        int start = 0, maxIndex = 0;
        for(int end = 0; end < s.length(); end++){
            maxIndex = Math.max(maxIndex, lastIndex[s.charAt(end) - 'a']);
            if(maxIndex == end){
                result.add(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
}
