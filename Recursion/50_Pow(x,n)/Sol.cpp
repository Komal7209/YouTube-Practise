class Solution {
public:
    
        double pow_util(double x, long n){
        if(n == 0) return 1.0;  // for power 0
        if(n ==1) return x;    //for power 1
        if(n < 0) return pow_util(1/x, -n);   //for negative power
        
        double result = pow_util(x*x , n/2);  //recursively calling itself again
        if(n%2) result *= x;   // if its odd then do this 
        return result;
    }
    
    
    double myPow(double x, int n) {
             return pow_util(x,n); 
    }
};