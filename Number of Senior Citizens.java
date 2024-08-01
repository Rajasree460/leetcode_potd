class Solution {
    public int countSeniors(String[] details) {
    int res=0;
    for(var x:details){  //x: This is the loop variable that will take on the value of each element in the details collection, one at a time.
        int age=Integer.parseInt(x.substring(11,13));
        if(age>60){
            ++res;
        }
    } 

     return res;   
    }
}
