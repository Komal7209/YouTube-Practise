// Tc: O(n)
// SC: O(n)

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {

        vector<int> ans;
        unordered_map<int, int> available;
        for (auto digit : digits)
            available[digit]++;

        auto check = [&](unordered_map<int, int> &req) { // due to & every variable above is captured and could be used inside this lambda function
            for (auto [digit, freq] : req)
            { // for(pair<int,int>x: req) // int digit = x.first, freq = x.second
                if (available[digit] < freq)
                    return false;
            }
            return true;
        };

        for (int i = 100; i < 999; i++)
        { // for trailing 0 check

            if (i % 2 == 0)
            { // for even number check

                unordered_map<int, int> have;

                int num = i;
                // for extracting individual number
                int a = num % 10;
                num /= 10;
                int b = num % 10;
                num /= 10;
                int c = num % 10;

                // for keeping track of all digit which are not even in available map
                have[a]++, have[b]++, have[c]++;

                if (check(have))
                    ans.emplace_back(i);
            }
        }
        return ans;
    }
};