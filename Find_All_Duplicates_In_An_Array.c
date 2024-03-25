int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(sizeof(int) * numsSize); // Allocate memory for result
    *returnSize = 0; // Initialize returnSize to 0
    
    // Iterate through the array
    for (int i = 0; i < numsSize; ++i) {
        int index;
        // Check if the number is positive
        if (nums[i] > 0) {
            index = nums[i] - 1; // Convert to zero-based index
        } 
        // Otherwise, if the number is negative
        else {
            index = -nums[i] - 1; // Convert to zero-based index
        }
        
        // Check if the number at calculated index is negative
        if (nums[index] < 0) {
            result[(*returnSize)++] = index + 1; // Add the duplicate to the result array
        } 
        // If not, mark the element as visited
        else {
            nums[index] = -nums[index];
        }
    }
    
    // Reset the array to its original state
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] < 0) nums[i] = -nums[i];
    }

    return result; // Return the result array
}
