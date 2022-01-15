class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target)
    {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }

    void findCombination(vector<vector<int>> &res, const int order, const int target, vector<int> &local, const vector<int> &num)
    {
        if (target == 0)
        {
            return res.push_back(local);
        }

        for (int i = order; i < num.size(); i++) // iterative component
        {
            if (num[i] > target)
                return;
            if (i == order || num[i] != num[i - 1])
            { // check duplicate combination and runs only when it is first element out of duplicates

                local.push_back(num[i]),
                    findCombination(res, i + 1, target - num[i], local, num); // recursive componenet
                local.pop_back();
            }
        }
    }
};