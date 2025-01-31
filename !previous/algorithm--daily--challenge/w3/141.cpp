/*Runtime: 7 ms, faster than 98.14% of C++ online submissions for Linked List Cycle.
Memory Usage: 8 MB, less than 58.37% of C++ online submissions for Linked List Cycle.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* a = head;
        ListNode* b = head;
        
        while(a&&b){
            a = a->next;
            b = b->next;
            if(!b) return false;
            b = b->next;
            
            
            if(a==b) return true;
        }
        
        
        
        return false;
    }
};