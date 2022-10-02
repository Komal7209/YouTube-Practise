class Solution {
public:
    int minimizeXor(int num1, int num2) {
        if(num1 == num2) return num1;
        int cnt2 = 0;
        
        
        // counting set bits of num2 as bits should be equal to num2
        for(int i = 0 ; i < 32; i++){
            if((num2&(1<<i))) cnt2++;
        }
        int ans = 0;
        
        // xor of 1 and 1 is 0 , so minimizing num1 by setting bits in ans
        for(int i = 31 ; i >= 0 ; i--){
            if(num1&(1<<i)){ // if bit is set for num1 from msb side
                ans |= (1<<i); // setting bits which are not set in ans so that we can minimize our ans
                cnt2--; // as we only want those number of bits to be set which are set in num2
                if(cnt2 == 0) break; // this could be the case when number of bits set in num1 > num2
            }
        }
        
        // number of  bits in ans should be same as num2 so setting in ans , the unset bits of num1
        if(cnt2 > 0){
            for(int i = 0 ; i < 32 ; i++){ // now setting the bits from lsb if bit set is not equal to num2
                if((num1&(1<<i)) == 0){ // if that bit is not set in num1 
                    ans |= (1<<i);      // then we are setting in our ans
                    cnt2--;
                    if(cnt2 == 0) break;
                }
            }
        }
        
        return ans;

    }
};