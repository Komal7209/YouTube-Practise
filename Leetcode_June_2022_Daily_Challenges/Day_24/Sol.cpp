// TC: O(NlogN)
// SC: O(N)


class Solution {
public:
    
    
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        unsigned int sum = 0; // to increase range else we could have used long
        for (int x : target){
            sum += x, pq.push(x);
        }
        
        while (pq.top() != 1) {
            int max_ele = pq.top();
           
            pq.pop();
            sum-=max_ele;
           
            if (max_ele<= sum || sum < 1) return false; // sum<1 for avoiding negative , max_ele <= sum for avoiding element becoming  0 as we need 1 not 0
            max_ele%= sum; // so that rather than subtracting continuosuly, we can subtract straught forward
            
           
            sum+=max_ele;  // updating sum with new value
           
            pq.push(max_ele ? max_ele : sum); // pushing that ele until it becomes 1 else push new sum obtained for further operation i.e when no more we can insert into priority queue
           
        }
        
        return true;
        
        
    }
};