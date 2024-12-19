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
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow{head}, *fast{head->next};
        
        
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        
        
        ListNode* head2 = reverse(slow->next);
        slow->next = nullptr;
        
        
        while(head && head2)
        {
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev{nullptr};
        while(head)
        {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};