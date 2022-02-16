class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* start = new ListNode(0); //make head no longer a special case
        start->next = head;
        
    //traversing linkedlist and calling swapping function for each pair

        ListNode *cur = start;
        while (cur->next != NULL && cur->next->next != NULL) {
            cur->next = swap(cur->next, cur->next->next);
            cur = cur->next->next;
        }
        return start->next;
    }
    
    //swapping nodes
    
    ListNode* swap(ListNode* next1, ListNode* next2) {
        next1->next = next2->next;
        next2->next = next1;
        return next2;
    }
};
