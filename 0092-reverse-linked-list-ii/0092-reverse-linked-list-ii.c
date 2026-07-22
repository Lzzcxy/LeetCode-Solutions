/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* pre = &dummy;
    
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    
    struct ListNode* cur = pre->next;
    
    for (int i = 0; i < right - left; i++) {
        struct ListNode* next = cur->next; 
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    
    return dummy.next;
}