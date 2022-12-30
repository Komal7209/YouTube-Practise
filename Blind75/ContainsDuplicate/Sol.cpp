class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int>duplicates;

        for( int i : nums)
        {
            if(duplicates.count(i)) return true;
            else duplicates.insert(i);
        }

        return false;
    }
};


// tc : O(n)
//sc :O (n)