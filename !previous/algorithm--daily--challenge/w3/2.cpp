/*
Runtime: 31 ms, faster than 96.65% of C++ online submissions for Add Two Numbers.
Memory Usage: 70.9 MB, less than 97.66% of C++ online submissions for Add Two Numbers.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool n = false;
        
        ListNode* l1_head = l1;

        ListNode* l1_tmp = nullptr;
        
        while(l1 && l2){
            if(n) l1->val +=1;
            n=false;
            l1->val = l1->val + l2->val;
            
            if(l1->val>=10){
                n = true;
                l1->val -= 10;
            }
            
            if(!l1->next) l1_tmp = l1;
            
            l1 = l1->next;
            l2 = l2->next;
            
            
        }
        
        
        if(l2) {
            l1_tmp ->next = l2;
            l1= l2;
        }
        
        
        
        while(l1){
            
            if(n) l1->val +=1;
            n = false;
            
            if(l1->val>=10){
                n = true;
                l1->val -= 10;
            }
            
            
            if(!l1->next) l1_tmp = l1;
            
            l1 = l1->next;
        }
       
        
        if(n){
            ListNode* last = new ListNode(1);
            l1_tmp->next = last;
        }
        
        
        return l1_head;
    }
};