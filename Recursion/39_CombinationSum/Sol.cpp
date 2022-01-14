class Solution
{
public:
    void elementSum(vector<int> &candidates, vector<vector<int>> &res, vector<int> &elements, int target, int begin)
    {

        if (!target)
        {
            return res.push_back(elements);
        }

        for (int i = begin; i < candidates.size() && candidates[i] <= target; i++)
        {
            elements.push_back(candidates[i]);
            elementSum(candidates, res, elements, target - candidates[i], i);
            elements.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> elements;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        elementSum(candidates, res, elements, target, 0);
        return res;
    }
};
