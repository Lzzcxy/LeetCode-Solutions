/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1,struct ListNode *list2){
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *cur = &dummy;
    while (list1 != NULL && list2 != NULL){
        if (list1 -> val <= list2 -> val){
            cur -> next = list1;
            list1 =list1 -> next;
        } else {
            cur -> next = list2;
            list2 = list2 -> next;
        }
        cur = cur -> next;
    }
    cur -> next = (list1 != NULL) ? list1 : list2;
    return dummy.next;
}

struct ListNode *merge(struct ListNode **lists, int left, int right){
    if (left > right){
        return NULL;
    }
    if (left == right){
        return lists[left];
    }
    int mid = left + (right - left)/2;
    struct ListNode *l1 = merge(lists, left, mid);
    struct ListNode *l2 = merge(lists, mid+1, right);
    return mergeTwoLists(l1, l2);
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return merge(lists, 0, listsSize-1);
}