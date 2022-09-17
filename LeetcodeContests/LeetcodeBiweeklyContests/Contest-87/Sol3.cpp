class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& A) {
        int last[30] = {}, n = A.size();
        vector<int> res(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 30; ++j) {
                if (A[i] & (1 << j)) // it helps us to figure out that which bit is helping us in max OR
                    last[j] = i;
                res[i] = max(res[i], last[j] - i + 1);// we need to find an element that is farthest from the index i, but without which we will not be able to get maximum res[i].
                // res[i] = farthest element that contributes to the answer(that index) - current index +1(as min 1 length would be there).
            }
        }
        return res;
    }
};
