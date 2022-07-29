// TC:O(N*L)
// SC:(N*L)

class Solution {
private:
    bool isMappedToSame(string s1, string s2){
        int n = s1.size();
        
        unordered_map<char, char> mapping;
        vector<bool>seen(26,false);
        
        for(int i =0; i<n; i++){
            char wordChar = s1[i], patternChar = s2[i];
            
            if(mapping[wordChar] && mapping[wordChar] != patternChar)
                return false;
            if(!mapping[wordChar] && seen[patternChar -'a'])
                return false;
            
            mapping[wordChar] = patternChar, seen[patternChar -'a'] = true;
        }
        return true;        
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(string word : words)
            if(isMappedToSame(word, pattern)) ans.push_back(word);
        return ans;
    }
};