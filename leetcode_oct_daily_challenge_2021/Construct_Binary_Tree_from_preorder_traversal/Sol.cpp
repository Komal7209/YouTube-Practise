class Solution {
private: int index =0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstHelper(preorder, INT_MIN, INT_MAX);
    }
    TreeNode* bstHelper(vector<int>&preorder , int start , int end){
        if(index >= preorder.size() || preorder[index] < start || preorder[index] >end) return NULL;
        int val = preorder[index++];
        TreeNode* node = new TreeNode(val);
        node->left = bstHelper(preorder, start, val);
        node->right = bstHelper(preorder, val, end);
        return node;
    }
};