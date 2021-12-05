class Solution
{
private:
    string pathStartValue, pathEndValue;

public:
    // tc: O(n) // n-> no. of nodes
    void find(TreeNode *root, const int targetVal, string &currPath, string &ans)
    {
        if (!root)
            return;
        if (root->val == targetVal)
        {
            ans = currPath;
            return;
        }

        currPath += 'L';
        find(root->left, targetVal, currPath, ans);
        currPath.pop_back();

        currPath += 'R';
        find(root->right, targetVal, currPath, ans);
        currPath.pop_back();
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {

        // find = root , targetValue , currString , ansString
        string curr1, curr2;
        find(root, startValue, curr1, pathStartValue);
        find(root, destValue, curr2, pathEndValue);

        // reverse // Tc: O(n)
        auto rev = [](string &s)
        { reverse(s.begin(), s.end()); };

        // remove common path // TC: O(1)
        auto removeCommonPath = [](string &a, string &b)
        {
            while (a.length() and b.length() and (a.back() == b.back()))
                a.pop_back(),
                    b.pop_back();
        };

        // make all character to 'U' // TC:O(n)
        auto modifyUp = [](string &a)
        {            for(auto &i : a)                i = 'U'; };

        // remove  the common path

        // reversing
        rev(pathStartValue);
        rev(pathEndValue);

        // removing
        removeCommonPath(pathStartValue, pathEndValue);

        // reversing
        rev(pathStartValue);
        rev(pathEndValue);

        // modigying to up
        modifyUp(pathStartValue);

        // concatenating
        return pathStartValue + pathEndValue;
    }
};
