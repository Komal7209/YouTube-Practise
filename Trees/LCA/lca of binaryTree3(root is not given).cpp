// variation of above ques
// root node is not given but below thing is given


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

// if root node is not given then we could make separate fn for finding root and then use same lca fn
/*
Intuition :
The difference from #236 is that we don't have access to root of the tree but we do have access to parent pointers. So inorder to drag unknown questions to similar questions that have been solved before, we can traverse using parent pointers from any of the given nodes to find the root node. Once the root is found, we can reuse the logic of #236. I have attached code for this below

Another way is to store the paths of node to root for both the given nodes, reverse the paths & check for the first divergence.
*/


class Solution {

 private:
     Node* getRoot(Node* p){
        while(p->parent!=nullptr){
            p = p->parent;
        }
        return p;
    }
    
    //exact same as #236
 Node* findLCA(Node* root, Node* p, Node* q) {
        
        if(!root){
            return nullptr;
        }
        
        //if node is equal to either p or q, return the node as LCA.
        if(root==p || root==q){
            return root;
        }
        
        //recurse on left & right subtree
        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);
        
        //if non-null is returned from both left & right subtrees, then the node
        //itself(root) is the LCA.
        if(left!=nullptr  && right != nullptr){
            return root;
        }
        
        //if null is returned from both subtrees, the node itself should return null.
        if(left==nullptr && right == nullptr){
            return nullptr;
        }
        
        //if either of left or right subtree is non-null, return the non-null node.
        return left!=nullptr ? left:right;
    }


    public:
     Node* lowestCommonAncestor(Node* p, Node* q) {
     Node* tempNode = p; 
     Node* root = getRoot(tempNode);//can send either p or q, doesn't matter. Goal is to get root
        //now since u have root, reuse #236
        return findLCA(root,p,q);
        
    }
    

};

/*
C++ Two Solutions: One by Checking Parent with Set, Another by checking children

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> visited;
        while (true) {
            if (p != nullptr && visited.count(p) == 0) {
                visited.insert(p);
                p = p->parent;
            } else if (p != nullptr) {
                return p;
            }
            if (q != nullptr && visited.count(q) == 0) {
                visited.insert(q);
                q = q->parent;
            } else if (q != nullptr) {
                return q;
            }
        }
        return nullptr;
    }
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while (p != nullptr) {
            if (IsDescestor(p, q)) return p;
            p = p->parent;
        }
        return nullptr;
    }
    bool IsDescestor(Node* p, Node* q) {
        if (p == q) return true;
        if (p->left != nullptr && IsDescestor(p->left, q)) return true;
        if (p->right != nullptr && IsDescestor(p->right, q)) return true;
        return false;
    }
};


*/