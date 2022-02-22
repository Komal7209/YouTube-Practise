class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(char c : s){
            int digit = c - 'A' + 1; // as starting from 1 thus add 1
            result = result*26 + digit;
        }
        return result;
    }
};  