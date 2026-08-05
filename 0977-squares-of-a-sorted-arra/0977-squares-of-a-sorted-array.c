/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *res = (int*)malloc(numsSize * sizeof(int));
    int left = 0;
    int right = numsSize - 1;
    int p = numsSize - 1;
    while(left <= right){
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        if(leftSquare > rightSquare){
            res[p] = leftSquare;
            left++;
        }else{
            res[p] = rightSquare;
            right--;
        }
        p--; 
    }
    return res;
}
