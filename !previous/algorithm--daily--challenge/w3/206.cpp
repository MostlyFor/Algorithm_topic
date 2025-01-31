Runtime: 25 ms, faster than 6.01% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.3 MB, less than 79.03% of C++ online submissions for Reverse Linked List.


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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* last = nullptr; 
        
        ListNode* head_copy = head;
        
        ListNode* tail = head;
        
        
        while(1){
            while(tail->next != last) tail = tail->next;
            
            //홀수용
            if(tail == head) break;
            
            int tmp = head->val;
            head->val = tail->val;
            tail->val = tmp;
            
            if(head->next == tail) break;
            
            last = tail;
            head = head->next;
            tail = head;
            
        } 
        
        return head_copy;
        
    }
};