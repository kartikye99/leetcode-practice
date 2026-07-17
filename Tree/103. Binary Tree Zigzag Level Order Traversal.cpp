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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>result;
        if(root==NULL) return result;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int levelsize = q.size();
            vector<int>ans;
            for(int i = 0 ; i < levelsize; i++){
                TreeNode *front = q.front();
                q.pop();
                ans.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(!flag){
                reverse(ans.begin(),ans.end());
            }
            result.push_back(ans);

            flag =!flag;
        }
        return result;
    }
};