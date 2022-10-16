// tc: O(n)
// sc: O(n)
class Solution {
private:
        void reverse(int num, int &ans)// 10000 
        { 
            while(num !=0)
            {   ans = ans*10 + num%10;
                num/=10;
            }
        } 
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s; // O(1)
        int ans =0;
        
        for(int num: nums) // O(n)
        {     
            reverse(num,ans);
            s.insert(num);
            s.insert(ans);  
            ans =0;
        }
        
        return s.size();
    }
};