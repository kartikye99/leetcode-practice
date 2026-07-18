/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> kdistance(int k, Node *root) {
        // code here
        vector<int>result;
        queue<Node*>q;
        int count = 0;
        if(root==NULL){
            return result;
        }
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            for(int i = 0 ; i<level;i++){
                Node* front = q.front();
                q.pop();
                if(count == k){
                result.push_back(front->data);
                }
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            count++;
        }
        
        return result;
    }
};