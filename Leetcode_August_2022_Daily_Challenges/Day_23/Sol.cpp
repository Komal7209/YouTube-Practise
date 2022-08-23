class Solution {
public:
    
    // we requires to reverse the list     
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next== NULL) return head;
        ListNode* rest_head = reverseList(head->next);
        ListNode* rest_tail = head->next;
        rest_tail->next = head;
        head->next = NULL;
        return rest_head;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        
        //for reaching mid
        ListNode* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<slow->val;
        // now reversing till end
        ListNode* rev = reverseList(slow->next);
        
        ListNode* curr = head;
        while(rev!= NULL){ // traversing reversed list and comparing with original half list
            if(rev->val != curr->val) return false;
            rev= rev->next; // moving next
            curr = curr->next; // moving next
            
        }
        return true;       
        
    }
};