class Solution {
    public String makeFancyString(String s) {
        // A mutable sequence of characters, meaning it can be modified. StringBuilder is generally more efficient for cases where you need to modify/concatenate the contents of a string frequently, like in a loop.

        StringBuilder res=new StringBuilder();
        res.append(s.charAt(0));
        
        int ct=1;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)==res.charAt(res.length()-1)){
                ct++;
                if(ct<3){   //to ignore the 3rd same char
                    res.append(s.charAt(i));
                }
            }else{
                ct=1;
                res.append(s.charAt(i));
            }
        }

        return res.toString();
    }
}
