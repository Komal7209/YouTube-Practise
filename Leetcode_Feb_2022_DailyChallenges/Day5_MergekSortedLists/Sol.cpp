

// Time complexity: O(nlogk) =>n no. of elements in largest list , k => no. of lists
// Space Complexity: O(k) 
/*

class Solution{
    private: 
        struct mycomparison {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    public:
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, mycomparison > heap;
        ListNode head(0); // dummy node
        ListNode *curNode = &head;
        int i, k = lists.size(); // vector size 
        for (i = 0; i < k; i++)  // putting all lists's top element(k) , so that all lists are used together
            if (lists[i]) heap.push(lists[i]);
        
        while (!heap.empty()){
            curNode->next = heap.top();
            heap.pop();
            curNode = curNode->next; // 0 = 0->1 => 1
            if (curNode->next) heap.push(curNode->next); // pushing next element of present list
        }
    return head.next;
   }
};

*/

// TC: O(nlogk)
// SC:O(1)


class Solution{
    public:
    
             //O(n)
          ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
              if(!list1 || (list2 && list1->val > list2->val))swap(list1,list2); 
              if(list1 && !list2) return list1;
              if(!list1 && list2) return list2;
              if(list1) list1->next = mergeTwoLists(list1->next, list2);
              return list1; 
          }
    
           ListNode *mergeKLists(vector<ListNode *> &lists) {
            
               if(lists.empty()) return NULL;
                    
               // O(logk)
               for(int k = lists.size(); k>1; k = (k+1)/2){ // k +k/2 + k/4...
               // O(k)
                   for(int i =0; i<k/2; i++){// k/2 + k/4 +k/8+ ..... + 1

                       lists[i] = mergeTwoLists(lists[i], lists[k-1-i]);
                   }
               }
               
               return lists[0];
               
           } 

      };