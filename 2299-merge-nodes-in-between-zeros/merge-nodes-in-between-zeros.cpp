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
    ListNode* mergeNodes(ListNode* head) {
        int s=0;
        head=head->next;
        ListNode* newhead=new ListNode(0);
        ListNode* curr=newhead;
        while (head){
            s+=head->val;
            if (!head->val){
                ListNode* temp=new ListNode(s);
                curr->next=temp;
                curr=temp;
                s=0;
            }
            head=head->next;
        }
        return newhead->next;
    }
};