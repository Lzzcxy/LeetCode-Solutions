/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = numsSize - k + 1;
    int* ans = (int*)malloc(sizeof(int) * (*returnSize));
    int* deque = (int*)malloc(sizeof(int) * numsSize);
    int head = 0;
    int tail = 0;
    for (int i = 0; i < numsSize; i++) {
        while (head < tail && nums[deque[tail - 1]] <= nums[i]) {
            tail--;
        }
        deque[tail++] = i;
        if (deque[head] <= i - k) {
            head++;
        }
        if (i >= k - 1) {
            ans[i - k + 1] = nums[deque[head]];
        }
    }
    free(deque);
    return ans;
}