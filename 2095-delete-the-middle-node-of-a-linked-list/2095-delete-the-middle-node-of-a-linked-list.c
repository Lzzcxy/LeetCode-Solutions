/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *slow = &dummy;
    struct ListNode *fast = &dummy;
    while (fast -> next != NULL && fast -> next ->next != NULL){
        slow = slow -> next;
        fast = fast -> next ->next;
    }
    struct ListNode *toDelete =slow -> next;
    slow -> next = slow ->next ->next;
    free(toDelete);
    return dummy.next;
}
