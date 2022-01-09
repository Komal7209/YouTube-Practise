class Solution {
private: vector<vector<int>> ans;
    
    void backtrack(int begin, int k,vector<int>&current,int n)
    {   
        if(current.size()==k) {   // base case
          return ans.push_back(current);
        }
        
        
        for(int i=begin;i<n+1;i++) // options
        {   
            
            current.push_back(i);  //consider the current element i
            backtrack(i+1,k,current,n); // generate combinations
            current.pop_back(); //proceed to n ext element
                  
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        backtrack(1,k,current,n);
        return ans; //return answer
    }
};