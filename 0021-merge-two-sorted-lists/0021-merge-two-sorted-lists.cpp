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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL && list2 == NULL){
            return list1;
        } else if(list1 != NULL && list2 == NULL){
            return list1;
        } else if(list1 == NULL && list2 != NULL){
            return list2;
        }

        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                dummy->next = list1;
                list1 = list1->next;
                dummy = dummy->next;
            } else {
                dummy->next = list2;
                list2 = list2->next;
                dummy = dummy->next;
            }
        }

        if(list1!= NULL){
            dummy->next = list1;
        } else if(list2 != NULL){
            dummy->next = list2;
        }

        return head->next;

    }
};