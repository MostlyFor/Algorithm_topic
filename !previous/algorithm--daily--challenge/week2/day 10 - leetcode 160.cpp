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
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        int d1 = 0;
        int d2 = 0;
        
        //O(N)
        while(p1){
            p1 = p1->next;
            d1++;
        }
        //O(M)
        while(p2){
            p2 = p2->next;
            d2++;
        }
        
        int dif = d1-d2;
        
        p1 = headA;
        p2 = headB;

        //차이만큼 이동하면 만약 교차점이 있다면 만나게 되어 있음.
        //O(max(N,M))
        for(int i=0; i<abs(dif);i++){
            if(dif>0) p1 = p1->next;
            else p2 = p2->next;
        }
        
        //O(max(N,M))
        while(p1){
            if(p1 == p2) return p1;
            p1= p1->next;
            p2= p2->next;
        }
        
        
        return p1;
    }
};