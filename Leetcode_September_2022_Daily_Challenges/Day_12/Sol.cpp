// As we can choose any token thus we can sort
// sorting will make easy to choose greater token so that we can use that power at later point of time to increase score
// if we have sufficient power to increase score then we can use our power

// TC: O(nlogn)
// SC: O(1)

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int left = 0, right = tokens.size() - 1, score = 0, ans = 0;
        sort(tokens.begin(), tokens.end());

        while (left <= right)
        {
            if (tokens[left] <= power)
            {
                score++;
                power -= tokens[left];
                left++;
                ans = max(ans, score);
            }
            else if (tokens[left] > power and score > 0)
            {
                power += tokens[right];
                right--;
                score--;
            }
            else
                return score;
        }
        return ans;
    }
};

