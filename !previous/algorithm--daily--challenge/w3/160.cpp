/*Runtime: 42 ms, faster than 98.64% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 14.6 MB, less than 32.59% of C++ online submissions for Intersection of Two Linked Lists.
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // list 1 size
        int size1 = 0;
        ListNode* p1 = headA;
        while(p1->next != NULL){
            size1++;
            p1 = p1->next;
        }
        
        size1 ++;
        
        //list 2 size
        int size2 = 0;
        ListNode* p2 = headB;
        while(p2->next != NULL){
            size2++;
            p2 = p2->next;
        }
        size2 ++;
        
      
        //check if intersection
        if(p1 != p2) return nullptr;
        
        
        // fill the gap
        if(size1 > size2){
            while(size1-size2){
                size1--;
                headA = headA->next;
            }
        }
        else
            while(size2-size1){
                size2--;
                headB = headB->next;
            }
        
        //find intersection
        while(headA != headB){
            headA = headA->next;
            headB = headB ->next;
        }
        
        
        return headA;
    }
};