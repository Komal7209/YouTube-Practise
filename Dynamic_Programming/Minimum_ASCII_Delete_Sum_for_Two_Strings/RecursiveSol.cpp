// recursive
class Solution
{
    private:
         int minimum(string a, string b, int m, int n){
            if(m==0 && n==0){
                return 0;
            } 
            else if(m<=0){ // so whatsoever is left in other string, that would be ans to equalise both
                return (int)b[n-1] + minimum(a, b, m, n-1);
            }
            else if(n<=0){
                return (int)a[m-1] + minimum(a, b, m-1, n);
            } 
            else{
                if(a[m-1] == b[n-1]){ // common thus move to next one for both strings
                    return minimum(a, b, m-1, n-1);
                } else {
                    return min( // as opp to maximum length of longest subsequence and as per ques they need lowest sum
                        a[m-1]+minimum(a, b, m-1, n),  // as we are taking a here 
                        b[n-1]+minimum(a, b, m, n-1)
                    );
                }
            }
        }
    public:
    
    int minimumDeleteSum(string a, string b) {
        return minimumTopDown(a,b,a.size(),b.size());
        return 0;
      }
    
};

