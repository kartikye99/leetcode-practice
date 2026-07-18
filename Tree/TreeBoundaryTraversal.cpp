/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int>ans;
  void left(Node* root){
      if(root==NULL ||(root->left==NULL && root->right == NULL)){
          return;
      }
      ans.push_back(root->data);
      if(root->left)left(root->left);
      else left(root->right);
      
  }
  
  void right(Node* root){
      if(root==NULL || (root->left == NULL && root->right==NULL)){
          return;
      }
      if(root->right)right(root->right);
      else right(root->left);
      ans.push_back(root->data);
  }
  
  void leaf(Node *root){
      if(root==NULL) return;
      
      if(root->left==NULL && root->right == NULL){
          ans.push_back(root->data);
          return;
      }
      leaf(root->left);
      leaf(root->right);
  }
  
    vector<int> boundaryTraversal(Node *root) {
        if(root == NULL) return {};
        ans.push_back(root->data);
        // code here
        left(root->left);
        leaf(root->left);
        leaf(root->right);
        right(root->right);
        return ans;
    }
};