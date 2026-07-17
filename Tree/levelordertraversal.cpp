/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }

        q.push(root);

        while(!q.empty()){
            int  levelsize = q.size();
            vector<int>level;
            for(int i = 0  ; i<levelsize;i++){
            TreeNode* f = q.front();
            q.pop();
            level.push_back(f->val);

            if(f->left != NULL){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
            }
            result.push_back(level);
        }

        return result;
    }
};