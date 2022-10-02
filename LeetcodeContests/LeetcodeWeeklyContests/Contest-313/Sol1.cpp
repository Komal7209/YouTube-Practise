class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int cnt = 0;
        int n = min(a, b); // as required with common

        for (int i = 1; i <= n; i++)
        {
            if (a % i == 0 && b % i == 0) // shows divisible by both
                cnt++;
        }
        return cnt;
    }
};