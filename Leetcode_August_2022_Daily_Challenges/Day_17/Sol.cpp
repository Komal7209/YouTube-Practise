
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int>counter;
        
        for ( int i: arr){
            counter[i]++;
        }
        
        priority_queue<int>q;
        int res =0, removed =0;
        
        for(pair<int, int> c: counter){
            q.push(c.second);
        }
        
        while(removed < arr.size()/2){
            removed += q.top();
            q.pop();
            res++;
        }
        
        return res;       
    }
};

// TC: O(nlogn)
// SC: O(n)
