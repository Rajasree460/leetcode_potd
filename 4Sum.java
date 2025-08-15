class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums); // Step 1: Sort the array

        int n = nums.length;

        // Step 2: First loop for first element
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i

            // Step 3: Second loop for second element
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for j

                int left = j + 1;
                int right = n - 1;

                // Step 4: Two-pointer search
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right]; // use long to avoid overflow

                    if (sum == target) {
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));

                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
}
