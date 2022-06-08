class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while(ptr1 != ptr2){
            ptr1 = ptr1 == NULL ? headB : ptr1->next; 
            ptr2 = ptr2 == NULL ? headA : ptr2->next;
        }
        
        return ptr1;
    }
}