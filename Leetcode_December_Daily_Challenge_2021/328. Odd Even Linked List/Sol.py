class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head==None or head.next==None): return head
        odd = head
        even = head.next
        evenHead = even
        oddHead = odd
        
        while(even!=None and even.next!=None):
            odd.next = even.next
            even.next = even.next.next
            
            odd = odd.next
            even = even.next
        
        odd.next = evenHead
        
        return head