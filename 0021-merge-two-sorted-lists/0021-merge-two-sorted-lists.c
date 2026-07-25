/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *cur = &dummy;
    while (list1 != NULL && list2 != NULL){
        if(list1 -> val <= list2 -> val){
            cur -> next = list1;
            list1 = list1 -> next;
        }else{
            cur -> next = list2;
            list2 = list2 -> next;
        }
        cur = cur -> next;
    }
    if(list1 != NULL){
        cur -> next = list1;
    }else{
        cur -> next = list2;
    }
    return dummy.next;
}