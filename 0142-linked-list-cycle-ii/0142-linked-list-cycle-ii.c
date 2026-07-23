/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            struct ListNode *p1 = head;
            struct ListNode *p2 = slow;
            while(p1 != p2){
                p1 = p1 -> next;
                p2 = p2 ->next;
            }
            return p1;
        }
    }
    return NULL;
}