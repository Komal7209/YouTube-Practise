class Solution {
public:
    Node* connect(Node* root) {
        // using bfs for storing nodes at each level
        queue<Node*>q;
        if(!root) return NULL;
        q.push(root);
        q.push(NULL); // for root node
        
        while(!q.empty()){
            
            Node* currNode = q.front();
                q.pop();
            
            if(currNode!=NULL){
                
                currNode->next = q.front();
                
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                    
            }
            else if (!q.empty()){ // when null is reached for curr element then at that moment curr's left n right would already be pushed thus we are required to push null for those
                q.push(NULL);
            }
        }
        return root;
    }
};