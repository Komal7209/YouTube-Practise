// top down 
class Solution{
    private:
         
 int minimumTopDown(string&a, string&b, int m, int n, vector<vector<int>>& res){
    if(res[m][n] != -1){
        return res[m][n];
    } 
     
  else   if(m==0 && n==0){
        return res[m][n] = 0;
    } 
     
  else   if(m==0){
        return res[m][n] = (int)b[n-1] + minimumTopDown(a, b, m, n-1, res);
    } 
     
   else  if(n==0){
        return res[m][n] = (int)a[m-1] + minimumTopDown(a, b, m-1, n, res);
    }
        
   else{
       if(a[m-1]==b[n-1]){
            return res[m][n] = minimumTopDown(a, b, m-1, n-1, res);
        } else {
            return res[m][n] = min(
                (int)a[m-1]+minimumTopDown(a, b, m-1, n, res),
               (int)b[n-1]+minimumTopDown(a, b, m, n-1, res)    
            );
        }
   }
 }
        
    public:
        int minimumDeleteSum(string a, string b) {
        vector<vector<int>>res(a.size()+1, vector<int>(b.size()+1, -1));
        return minimumTopDown(a,b,a.size(),b.size(), res);
        return 0;
    }


};




