
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(diff))
                {
                    diff = target - sum;
                }
                if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return target - diff;
    }
};
