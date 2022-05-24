// TC: O(n)
// SC:O(1)

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left =0, right =0, maxlength =0;
        
        // left to right traversal
        for( int i =0; i<s.size(); i++){
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(left == right)
                maxlength = max(maxlength, 2*right);
            else if(right >= left)
                left = right =0;            
        }
        
        // right to left traversal
        left =right = 0;
        
        for( int i = s.size()-1; i>=0; i--){
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(left == right)
                maxlength = max(maxlength, 2*left);
            else if (left >= right)
                left = right =0;            
        }
        
        return maxlength;
    }
};