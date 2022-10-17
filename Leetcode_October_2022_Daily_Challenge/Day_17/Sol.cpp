class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        unordered_set<char>s;
        
        for(char c: sentence)
        {
            s.insert(c);
        }
        
        return s.size() == 26;
    }
};

// tc: O(n)
// sc: O(1)