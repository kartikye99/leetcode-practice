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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>result;
        if(root==NULL){
            return result;
        }
        int last = 0;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            vector<int>ans;
            for(int i = 0 ; i<level; i++){
                TreeNode *front = q.front();
                q.pop();
                ans.push_back(front->val);

                //last = front->val
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            last = ans[ans.size()-1];
            result.push_back(last);
            //result.push_back(last);
            last = 0;

        }
        return result;
    }
};