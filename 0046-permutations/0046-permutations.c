/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* nums, int numsSize, int first, int*** ans, int* returnSize, int* capacity, int** colSizes) {
    if (first == numsSize) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *ans = realloc(*ans, sizeof(int*) * (*capacity));
            *colSizes = realloc(*colSizes, sizeof(int) * (*capacity));
        } 
        int* current = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            current[i] = nums[i];
        }        
        (*colSizes)[*returnSize] = numsSize;
        (*ans)[(*returnSize)++] = current;
        return;
    }
    for (int i = first; i < numsSize; i++) {
        int temp = nums[first]; nums[first] = nums[i]; nums[i] = temp;
        backtrack(nums, numsSize, first + 1, ans, returnSize, capacity, colSizes);
        temp = nums[first]; nums[first] = nums[i]; nums[i] = temp;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;
    *returnSize = 0;
    int** ans = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    backtrack(nums, numsSize, 0, &ans, returnSize, &capacity, returnColumnSizes);
    return ans;
}