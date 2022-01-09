class Solution {
public:
   vector<vector<int>> permuteUnique(vector<int>& nums) {
	    vector<vector<int>>result;
        set<vector<int>>uniques; // for storing unique vectors
       
	    sort(nums.begin(), nums.end()); // here sorting is required for easily detecting duplicates
	    permuteRecursive(nums, 0, uniques);
       
       for(vector<int>x : uniques) // for storing unique vectors to answer
           result.push_back(x);
       
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> nums, int begin, set<vector<int>>&uniques)	{
		if (begin >= nums.size()) { // base case, no unnecessary exploration required now on...
		    // one permutation instance
           // cout<<uniques.size();
		    uniques.insert(nums);
		    return;
		}
		
		for (int i = begin; i < nums.size(); i++) {
             if(i > begin && nums[i] == nums[i-1]) continue; // for avoiding swapping of same element which are greater than begin
		    swap(nums[begin], nums[i]);
		    permuteRecursive(nums, begin + 1, uniques);
		}
    }
};
