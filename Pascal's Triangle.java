class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();

        for(int n = 1;n<=numRows;n++){
            List<Integer> a = new ArrayList<>();
            a.add(1);
            int value = 1;
            for(int c = 1;c<n;c++){
                value = value * (n - c);
                value /= c;
                a.add(value);
            }
            ans.add(a);
        }

        return ans;
        
    }
}

// class Solution {
//     public List<List<Integer>> generate(int numRows) {
//         if (numRows == 0) return new ArrayList<>();
//         if (numRows == 1) {
//             List<List<Integer>> result = new ArrayList<>();
//             result.add(Arrays.asList(1));
//             return result;
//         }
        
//         List<List<Integer>> prevRows = generate(numRows - 1);
//         List<Integer> newRow = new ArrayList<>();
        
//         for (int i = 0; i < numRows; i++) {
//             newRow.add(1);
//         }
        
//         for (int i = 1; i < numRows - 1; i++) {
//             newRow.set(i, prevRows.get(numRows - 2).get(i - 1) + prevRows.get(numRows - 2).get(i));
//         }
        
//         prevRows.add(newRow);
//         return prevRows;
//     }
// }
