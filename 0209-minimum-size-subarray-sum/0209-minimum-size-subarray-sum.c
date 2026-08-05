#include<limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int sum = 0;
    int minlen = INT_MAX;
    for(int right = 0; right < numsSize; right++){
        sum = sum + nums[right];
        while(sum >= target){
            int currentlen = right - left + 1;
            if(currentlen < minlen){
                minlen = currentlen;
            }
            sum = sum - nums[left];
            left++;
        }
    }
    return minlen == INT_MAX ? 0 : minlen;
}