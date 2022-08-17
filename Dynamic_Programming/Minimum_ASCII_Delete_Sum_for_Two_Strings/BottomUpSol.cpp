
class Solution{
    private:
         
// botttom up
int minimumBottomUp(string a, string b, int m, int n){
    int res[m+1][n+1]; // it is auto converting char to ascii code
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 && j==0){
                res[i][j] = 0;
            } else if(i<=0 && j>=0){
                res[i][j] = (int)b[j-1] + res[i][j-1];
            } else if(j<=0 && i>0) {
                res[i][j] = (int)a[i-1] + res[i-1][j];
            } else {
                if(a[i-1]==b[j-1]){
                    res[i][j] = res[i-1][j-1];
                } else {
                    res[i][j] = min(a[i-1]+res[i-1][j], b[j-1]+res[i][j-1]);
                }
            }
        }
    }
    
    return res[m][n];
}

public:
        int minimumDeleteSum(string a, string b) {
        return minimumBottomUp(a,b,a.size(),b.size());
    }
};


