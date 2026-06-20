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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* p = head;
        while(p){
            v.push_back(p);
            p = p->next;
        }

        int tar = v.size() - n;
        if(tar == 0) return head->next;
        
        v[tar-1]->next = v[tar]->next;

        return head;        
    }
};
