/*
class Solution {
public:
    string reverseVowels(string s) {
        stack<char>st;
        
       for(int i =0; i<s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
              ||s[i] == 'A' ||s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||s[i] =='U')
            {   
                st.push(s[i]);
            }
        }
        
        for(int i =0; i<s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
              ||s[i] == 'A' ||s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||s[i] =='U')
            {
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};
*/

class Solution {
private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
              ||c == 'A' ||c == 'E' || c == 'I' || c == 'O' ||c=='U');
        
    }
public:
    string reverseVowels(string s) {
        
        int left = 0, right = s.size()-1;
        
        while(left<right)
        {
            while(left < s.size() and !isVowel(s[left]))
            {
                left++;
            }
            
            while(right >= 0 and !isVowel(s[right]))
            {
                right--;
            }
            
            if(left<right)
                swap(s[left++], s[right--]);
        }
        return s;
    }
};
