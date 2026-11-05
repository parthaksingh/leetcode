/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
       ListNode dummy(0);
       while(head != NULL){
        ListNode* curr = head;
        head = head->next;
        ListNode* prev = &dummy;

        while(prev->next != NULL && prev->next->val <= curr->val){
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
       } 
       return dummy.next;
    }
};