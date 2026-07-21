/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cur = &dummy;
    while (cur -> next != NULL){
        if(cur -> next-> val == val){
            struct ListNode* tmp = cur -> next;
            cur -> next = cur -> next -> next;
        }
        else{
            cur = cur -> next;
        }
    }
    return dummy.next;
}