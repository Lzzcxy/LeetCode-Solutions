/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
typedef struct Node {
    int val;
    struct Node* next;
} Node;
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    Node** bucket = (Node**)calloc(numsSize + 1, sizeof(Node*));
    int count = 1;
    for (int i = 0; i < numsSize; i++) {
        if (i < numsSize - 1 && nums[i] == nums[i + 1]) {
            count++;
        } else {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = nums[i];
            newNode->next = bucket[count];
            bucket[count] = newNode;           
            count = 1;
        }
    }
    int* ans = (int*)malloc(sizeof(int) * k);
    *returnSize = 0;
    for (int freq = numsSize; freq >= 1 && *returnSize < k; freq--) {
        Node* curr = bucket[freq];
        while (curr != NULL && *returnSize < k) {
            ans[(*returnSize)++] = curr->val;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(bucket);
    return ans;
}