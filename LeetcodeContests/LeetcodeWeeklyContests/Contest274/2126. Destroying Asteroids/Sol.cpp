// Approach:

// Sort array in increasing order
// Start destroying astroid with smallest weight return false if any point it is not possible.

class Solution
    // TC: O(nlogn)
    // SC: O(1)
{
    public:
    bool asteroidsDestroyed(int mass, vector<int>& arr)
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long currentmass =mass;
        for (int i=0;i<n;i++)
        {
            if (arr[i]<=currentmass)
                currentmass+=arr[i];
            else
                return false;
        }
        return true;
    }
};