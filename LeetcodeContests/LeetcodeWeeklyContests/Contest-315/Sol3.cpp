// tc: O(n)
// sc: O(1)

class Solution {
    private:
        void reversed(int num, int &reverse)
        {
            while(num){
                reverse = reverse*10 + num%10;
                num = num/10;
            }
        }
public:
    bool sumOfNumberAndReverse(int nums) {
        
        for(int i = 0; i <= nums; ++i){ 
            int num = i;
            int reverse = 0;
            reversed( num, reverse);
            if(reverse + num == nums) return true;
        }
        return false;
    }
};