/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head == NULL ||head -> next == NULL){
        return true;
    }
    int vals[100005];
    int size = 0;
    struct ListNode *curr = head;
    while(curr != NULL){
        vals[size++] = curr -> val;
        curr = curr -> next;
    }
    int left = 0;
    int right = size - 1;
    while(left < right){
        if(vals[left] != vals[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
