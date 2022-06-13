/*

// recursive


class Solution {
private:
       int minTotalUtil(vector<vector<int>>& triangle, int row, int col) {
        
       if(row == triangle.size()) {
             return 0;
        }  
        //      present block           // next row same col             // next row but checking for next col
        return triangle[row][col]+min(minTotalUtil(triangle, row+1, col),minTotalUtil(triangle, row+1, col+1));
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         
          return minTotalUtil(triangle, 0, 0);
    }
};

*/
/*
// memoised
class Solution {
private: 
       int minTotalUtil(vector<vector<int>>& triangle, int row, int col,vector<vector<int>> &v) {
        if(row == triangle.size()) {
             
            return 0;
        }
         if(v[row][col]!=-1) return v[row][col];  
        
        return v[row][col]=triangle[row][col]+min(minTotalUtil(triangle, row+1, col,v),minTotalUtil(triangle, row+1, col+1,v));
    }
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
          int row=triangle.size(),col;
         col=row;
        vector<vector<int>> v(row,vector<int> (col,-1));
          minSum=minTotalUtil(triangle, 0, 0,v);
        
        return minSum;
        
    }
};

*/
// bottom up:
/*
 class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
          int row=triangle.size(),col;
         col=row;
        vector<vector<int>> v(row,vector<int> (col,0));
         v[0][0]=triangle[0][0]; // root value
         for(int i=1;i<row;i++) // as root was already included
         {
             for(int j=0;j<triangle[i].size();j++) // for that row
             {
                 if(j==0) 
                    v[i][j]=v[i-1][j]+triangle[i][j]; // as first col thus add previous row with present value
                 else if(j==triangle[i].size()-1)    // as last col, previous would be only having j-1 cols thus we need this case 
                    v[i][j]=v[i-1][j-1]+triangle[i][j];
                 else
                     v[i][j]=min(v[i-1][j-1],v[i-1][j])+triangle[i][j]; // main recurrence relation
             }
              
         }
         
        return *min_element(v[row-1].begin(),v[row-1].end()); // we'll be having ans in our last row
         
        
    }
};

*/
// bottom up without using extra space:

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
          int row=triangle.size();
         for(int i=1;i<triangle.size();i++)
         {
             for(int j=0;j<triangle[i].size();j++)
             {
                 if(j==0) 
                     triangle[i][j]=triangle[i-1][j]+triangle[i][j]; // for first col of each row we have 1 option that is to add from previous row
                 else if(j==triangle[i].size()-1) 
                     triangle[i][j]=triangle[i-1][j-1]+triangle[i][j]; // for last col of each row we have 1 option to add from previous row, previous col
                 else
                    triangle[i][j]=min(triangle[i-1][j-1],triangle[i-1][j])+triangle[i][j]; // checking min out of last row's previous two cols
             }
              
         }
        
        return *min_element(triangle[row-1].begin(),triangle[row-1].end());
         
        
    }
};