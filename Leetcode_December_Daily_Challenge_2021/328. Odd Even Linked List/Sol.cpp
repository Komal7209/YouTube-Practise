class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL||head->next==NULL) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        ListNode *oddHead = odd;
        
        while(even!=NULL&&even->next!=NULL){
            odd->next = even->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
        
    }
};