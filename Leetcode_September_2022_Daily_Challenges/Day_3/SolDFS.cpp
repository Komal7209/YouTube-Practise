// TC: O(pow(2,n))
// SC: O(pow(2,n))

//dfs

class Solution {
private:
    vector<int> ans;
    void check(int num,int k,int n){
        if(n==1){
        ans.push_back(num);
        return;
        }
        
        if(num%10-k>=0)
        check(num*10+(num%10-k),k,n-1);
        
        if(k)
        {
        if(num%10+k<10)
        check(num*10+(num%10+k),k,n-1);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<10;i++) check(i,k,n);
        return ans;
    }
  
};

