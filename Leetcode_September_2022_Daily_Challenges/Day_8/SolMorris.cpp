

class Solution
{
    public:
    vector<int> inorderTraversal(TreeNode* root)
{
     vector<int> output;
     TreeNode *p=root,*temp;
     if(!root)return output;
     while(p){
         if(p->left==NULL)
         {
             output.push_back(p->val);
             p=p->right;
         }
         else{
             temp=p->left;
        // connect the right leaf with the root 
             while(temp->right!=NULL&& temp->right!=p)
             {temp=temp->right;}
             if(temp->right==NULL){
                 temp->right =p;
                 p = p->left;
             }
             else{
                 output.push_back(p->val);
                 temp->right=NULL;
                 p=p->right;
             }
         }
     }
    return output;
  }
};