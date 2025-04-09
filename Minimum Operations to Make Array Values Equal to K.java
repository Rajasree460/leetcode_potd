class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums); //sort the array
        int min=nums[0];

        if(min<k)
         return -1; //not possible, as mentioned
         //For each index i where nums[i] > h

        int ct=0;

        for(int i=0;i<nums.length; i++){
            if(nums[i]>k){
                ct++;   //just count unique elems
                while(i+1<nums.length && nums[i]==nums[i+1])       //if 2 elems are =, ignore it a7 move forward
                i++;
            }
        }

      return ct;  //how many unique elems are there that many operations are needed, so return count
    }
}
