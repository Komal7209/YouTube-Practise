// LC

// top down dp + dfs 
// TC: O(L*L*N)
// SC: O(N) => total words stored set and recursion stack 

// here we are starting from any word and then going to other word by taking out single letter and checking if that new word exists or not in the set=> if it exists then we will do dfs on that word

class Solution {
private:

    int dfs(unordered_set<string> &words, unordered_map<string, int> &counts, string currentWord) {
        // If the word is encountered previously we just return its value present in the map (memoization).
        if (counts.count(currentWord)) {
            return counts[currentWord];
        }
        // This stores the maximum length of word sequence possible with the 'currentWord' as the
        int maxLength = 1;

        // creating all possible strings taking out one character at a time from the `currentWord`
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            // If the new word formed is present in the list, we do a dfs search with this newWord.
            if (words.count(newWord)) {
                int currentLength = 1 + dfs(words,counts, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        counts[currentWord] = maxLength; // when that dfs call ends and it backtracks then this fills up

        return maxLength;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> counts;
        unordered_set<string> wordsPresent; // all word to put in set for better lookup
        for (const string &word : words) {
            wordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, dfs(wordsPresent, counts, word));
        }
        return ans;
    }
};

/*
// bottom up dp 
// TC: O(N *(logN + L*L)) => NLogN due to sorting + N*L*L for running L^2 loop for N words
// SC: O(N)

class Solution {
private:
    // increasing order of word length
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp; // word count
        int res = 0;
        for (string word : words) {
            for (int i = 0; i < word.length(); i++) {
                string newWord = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp.count(newWord)? dp[newWord] + 1: 1); // we are doing 1 so that now we are adding the word in map
            }
            res = max(res, dp[word]);
        }
        return res;
    }
};
*/