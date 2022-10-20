class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> values{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> roman{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int idx=roman.size()-1;
        
        string ans;
        
        while(num>0)
        {
            while(num<values[idx])
            {
                idx--;
            }
            
            int count = num/values[idx];
            num -= count*values[idx];
            
            while(count--)
            {
                ans+= roman[idx];
            }
        }
        return ans;
    }
};