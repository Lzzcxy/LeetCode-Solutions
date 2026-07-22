/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* temp = &dummy;
    
    while (temp->next != NULL && temp->next->next != NULL) {
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        
        temp = node1;
    }
    
    return dummy.next;
}