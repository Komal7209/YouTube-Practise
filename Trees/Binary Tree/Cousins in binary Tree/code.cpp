#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isCousins(TreeNode* root, int X, int Y) {
        
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
       
        while(!q.empty()){
            
        bool XFound = false;
        bool YFound = false;
            
            int levelSize = q.size();
            
            for( int i =0; i<levelSize; i++){
                
                TreeNode* currNode = q.front();
                q.pop();
                
                if(currNode->val == X) XFound = true;
                if(currNode->val == Y) YFound = true;

                
                if( currNode->left && currNode->right){
                    if((currNode->left->val == X && currNode->right->val == Y) || (currNode->left->val == Y && currNode->right->val == X)) return false;
                }
                
                if(currNode->left) q.push(currNode->left);
                if(currNode->right)q.push(currNode->right);   
            }
            
            if(XFound || YFound) flag = false;
            if( XFound && YFound) flag = true;
    
        } 
    return flag;
        
    }
}; 