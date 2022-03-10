class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2, int carry){
        if(!l1 && !l2 ){
            if(carry>0) return new ListNode(carry);
            return NULL;
        }
        
        //add, extract, next, reduce
        
        if(l1) carry+=l1->val;
        if(l2) carry+=l2->val;
        ListNode* head = new ListNode(carry%10);
        
        if(l1) l1 =l1->next;
        if(l2) l2 = l2->next;
        
        head->next = solve(l1, l2, carry/10);
        return head;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
};