//TC: O(n)
//SC:O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        unordered_set<int>sum;

        for(int num: nums) sum.insert(num);
        
        for(int i =0; i<n; i++){
            if(!sum.count(i)) return i;
        }
        
        return n; 
    }
};