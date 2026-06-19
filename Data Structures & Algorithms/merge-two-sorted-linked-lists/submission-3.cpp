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
        ListNode* list;
        if(!list1){
            list = list2;
            return list;
        }
        if(!list2){
            list = list1;
            return list;
        }
        if(list1->val >= list2->val){
            list = list2;
            list2 = list2->next;
        }
        else{
            list = list1;
            list1 = list1->next;            
        }
        ListNode* head = list;
        
        while(list1 && list2){
            if(list1->val >= list2->val){
                list->next = list2;
                list2 = list2->next;
                list = list->next;
            }
            else{
                list->next = list1;
                list1 = list1->next;
                list = list->next;
            }
        }
        if(list1) list->next = list1;
        if(list2) list->next = list2;

        return head;

    }
};
