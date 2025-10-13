import java.util.*;
public class Solution {
    public List<String> removeAnagrams(String[] words) {
        long hash = -1;
        List<String> res = new ArrayList<>();
        for (String w : words) {
            long new_hash = 0;
            for (char ch : w.toCharArray()) new_hash += (1L << (ch - 'a'));
            if (hash != new_hash) {
                res.add(w);
                hash = new_hash;
            }
        }
        return res;
    }
}
