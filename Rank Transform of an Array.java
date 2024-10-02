class Solution {
    public int[] arrayRankTransform(int[] arr) {
           int n = arr.length;
        int ans[] = new int[n];

        int carr[] = Arrays.copyOf(arr, n);
        Arrays.sort(carr);

        HashMap<Integer, Integer> map = new HashMap<>();

        int a = 1;
        for (int i = 0; i < n; i++) {

            if (map.containsKey(carr[i])) {

            } else {
                map.put(carr[i], a);
                a++;
            }
        }

        for (int i = 0; i < arr.length; i++) {
            ans[i] = map.get(arr[i]);
           
        }
    return ans;
    }
    
}
