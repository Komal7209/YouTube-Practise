// TC: O(N)
// SC: O(1)

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (char c: num) {
            cnt[c - '0']++;
        }
        
        string leftpartition, rightpartition; // left and right partition
        
         for (int i: num) {
            for (int j = 9; j >= 0; j--)  {
                if (cnt[j] > 1 && (j > 0 || leftpartition.size())) {
                    leftpartition += '0' + j;
                    rightpartition += '0' + j;
                    cnt[j] -= 2;
                    break;
                }
                // then due to outer loop it will start again
            }
         }
        
        // for single digits
        for (int i = 9; i >= 0; i--) {
            if (cnt[i]) {
                leftpartition += '0' + i; break;
            }
        }
        
        reverse(begin(rightpartition), end(rightpartition));
        return leftpartition + rightpartition;
    }
};

