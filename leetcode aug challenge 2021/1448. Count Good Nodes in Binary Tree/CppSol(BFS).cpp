class Solution {
public:
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int maxValue = INT_MIN;
        q.push({root, maxValue});
        int count = 0;
        
        while (!q.empty()) {
            auto pair_value = q.front();
            q.pop();
            TreeNode* currNode = pair_value.first;
            int currMax_value = pair_value.second;
            if (currNode->val >= currMax_value) {
                count++;
            }
            maxValue = max (currNode->val, currMax_value);
            if (currNode->left) {
                q.push({currNode->left, maxValue});
            }
            if (currNode->right) {
                q.push({currNode->right, maxValue});
            }
        }
        return count;
    }
};