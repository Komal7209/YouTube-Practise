class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<string>chars;
        stack<int>nums;
        int num =0;
                
        for(char c: s){  
            if(isalpha(c)){
                ans.push_back(c);
            }
            else if(isdigit(c)){
                num = num*10 + c-'0';
            }
            else if(c == '['){
                // at this moment all chars and nums are required to be gathered in their stacks
                // and required to empty the num and char(here ans)
                chars.push(ans);
                nums.push(num);
                ans = "";
                num = 0;
            }
            else if(c == ']'){
                string temp = ans;
                
                for(int i =0; i<nums.top() -1 ; i++)// depicts number inserted last time in the stack
                    ans+=temp;
                
                ans = chars.top() + ans; // bcoz at this moment 2nd set of char was not inserted into stack, only previous set was there and it helped to build whole answer
                chars.pop();
                nums.pop();              
            }          
        }
        return ans;
    }
};