//TC:O(n)
//SC:O(1)

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1=NULL;
        ListNode* p2=head; // initial postion of head
        ListNode* result = head; // initial position of head
        
        // from start
        while(--k>0)
        {
            head=head->next;
        }
        p1=head; // reached first node
        
        while(head->next!=NULL)
        {
            p2=p2->next; // until head reaches null , it will reach the last kth node
            head=head->next;
        }
        
        // swapping
        int temp = p2->val;
        p2->val=p1->val;
        p1->val=temp;
        
        return result;
        
    }
};