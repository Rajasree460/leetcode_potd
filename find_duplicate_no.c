int findDuplicate(int* nums, int numsSize) {
    // Initialize count array with size numsSize + 1
int count[numsSize + 1]; 
for (int i = 0; i <= numsSize; i++) {
    count[i] = 0; // Initialize count array
}


    // Count occurrences of each number
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    // Find the number with more than one occurrence (duplicate)
for (int i = 1; i <= numsSize; i++) {
    if (count[i] > 1) {
        return i;
    }
}


    // No duplicate found
    return -1;
}
