class Solution
{
public:
    bool findPath(TreeNode *root, vector<TreeNode *> &p, int n)
    {
        if (root == NULL)
            return false;
        p.push_back(root);
        if (root->val == n)
            return true;

        if (findPath(root->left, p, n) || findPath(root->right, p, n))
            return true;

        p.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2)
    {
        vector<TreeNode *> path1, path2;
        TreeNode *prev = NULL;
        if (findPath(root, path1, n1->val) == false || findPath(root, path2, n2->val) == false)
            return NULL;
        for (int i = 0; i < path1.size() && i < path2.size(); i++)
        {
            cout << "path1[i]"<< " " << path1[i]->val << " " << "path2[i]"<< " " << path2[i]->val << endl;
            
            if (path1[i] != path2[i])
            {                        // when not equal then previous one is returned
                return path1[i - 1]; //
            }
            prev = path1[i]; // when all are equal then store in prev
        }
        //  return NULL;
        return prev;
    }
};