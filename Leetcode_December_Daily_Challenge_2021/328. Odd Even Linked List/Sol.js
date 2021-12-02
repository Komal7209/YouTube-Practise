var oddEvenList = function(head) {
  if(head==null||head.next==null) return head;
  var odd = head;
  var even = head.next;
  var evenHead = even;
  var oddHead = odd;
  
  while(even!=null && even.next!=null){
      odd.next = even.next;
      even.next = even.next.next;
      
      odd = odd.next;
      even = even.next;
  }
  odd.next = evenHead;
  
  return head;

};