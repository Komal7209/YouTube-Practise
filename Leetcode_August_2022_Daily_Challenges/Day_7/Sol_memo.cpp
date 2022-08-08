// TC: O(N)
// SC: O(N)

// recursion + memoisation
// base case: i==0 return 1, because no character is also a permutation
// recurrence relation : vowelPermutationCount(int i, int vowel) on the basis of vowel

class Solution {
    private:
            vector<vector<long>> memo;
            int MOD = 1000000007;
    
    long vowelPermutationCount(int i, int vowel) {
        if (memo[i][vowel] != 0) return memo[i][vowel];
        if (i == 0) {
            memo[i][vowel] = 1;
        } else {
            if (vowel == 0) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 1) + vowelPermutationCount(i - 1, 2) + vowelPermutationCount(i - 1, 4)) % MOD;
            } else if (vowel == 1) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 0) + vowelPermutationCount(i - 1, 2)) % MOD;
            } else if (vowel == 2) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 1) + vowelPermutationCount(i - 1, 3)) % MOD;
            } else if (vowel == 3) {
                memo[i][vowel] = vowelPermutationCount(i - 1, 2);
            } else if (vowel == 4) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 2) + vowelPermutationCount(i - 1, 3)) % MOD;
            }
        }
        return memo[i][vowel];
    }
    
public:
    int countVowelPermutation(int n) {
        
        // each row stands for the length of string
        // each column indicates the vowels
        // specifically, a: 0, e: 1, i: 2, o: 3, u: 4
        memo = vector<vector<long>>(n, vector<long>(5));
        long result = 0;
        for (int i = 0; i < 5; i++){
            result = (result + vowelPermutationCount(n - 1, i)) % MOD;
        }
        return (int)result;
        
    }
};

