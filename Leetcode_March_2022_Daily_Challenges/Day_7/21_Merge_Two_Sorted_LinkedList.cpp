class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        //if either one of them is empty
        if(!l1) return l2;
        if(!l2) return l1;
        
        // maintaining head and tail pointer 
        ListNode* head = NULL, *tail = NULL;
        
        // starting the answer linkedlist and updating head and tail together, thus head issue resolved here
        if(l1->val <= l2->val){
            head =tail= l1;
            l1 = l1->next;
        }
        else{
            head = tail = l2;
            l2 = l2->next;
        }
        
        
        // just updating tail for making answer linkedlist
        while(l1 and l2){
            if(l1->val < l2->val){
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }        
        }
        
        if(!l2){
            tail->next = l1;
        }
        else//(!l1)
        {
            tail->next = l2;
        }
        
        // as now answer linkedlist is complete thus updating the final answer
        return head;
    }
};