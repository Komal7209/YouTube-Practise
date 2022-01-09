class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int>> result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		
        if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) { // 1,2,3 =>i 
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]); 
		}
    }
};