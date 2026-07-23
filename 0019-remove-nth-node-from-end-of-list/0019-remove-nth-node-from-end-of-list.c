/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdlib.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    int length = 0;
    struct ListNode* curr =head;
    while (curr != NULL){
        length++;
        curr = curr -> next;
    }
    int steps = length - n;
    curr = &dummy;
    for(int i = 0; i < steps; i++){
        curr = curr -> next;
    }
    struct ListNode* toDelete = curr -> next;
    curr -> next = curr -> next -> next;
    free(toDelete);
    return dummy.next;
}