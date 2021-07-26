//tc: O(nlogn)
//sc: O(1)

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0) return NULL;        
        return solve(nums, 0, nums.size()-1);
    }
    
    TreeNode* solve(vector<int>&arr, int start, int end){

        if(start>end) return NULL;
        int mid = start + (end-start +1)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = solve(arr, start, mid-1);
        root->right = solve(arr, mid+1, end);

        return root;
     }    
};