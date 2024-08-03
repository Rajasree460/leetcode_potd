// class Solution {
//     public boolean canBeEqual(int[] target, int[] arr) {
//         int[] cnt1 = new int[1001];
//         int[] cnt2 = new int[1001];
//         for (int v : target) {
//             ++cnt1[v];
//         }
//         for (int v : arr) {
//             ++cnt2[v];
//         }
//         return Arrays.equals(cnt1, cnt2);
//     }
// } 

class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        for(int i=0;i<target.length;i++)
        {
            if(target[i]!=arr[i])
            return false;
        }
        return true;
    }
}
