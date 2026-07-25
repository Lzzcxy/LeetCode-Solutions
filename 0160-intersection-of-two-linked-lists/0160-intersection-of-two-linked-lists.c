/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL){
        return NULL;
    }
    struct ListNode *pa = headA;
    struct ListNode *pb = headB;
    while (pa != pb){
        pa = (pa == NULL) ? headB : pa -> next;
        pb = (pb == NULL) ? headA : pb -> next;
    }
    return pa;
}