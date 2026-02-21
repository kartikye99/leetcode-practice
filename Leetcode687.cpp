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
    int max = 0;
public:
    int dfs(TreeNode* Node){
        if(Node==nullptr) return 0;

        int left = dfs(Node->left);
        int right = dfs(Node->right);
        int leftArrow = 0;
        int rightArrow = 0;

        if(Node->left && Node->left->val == Node->val){
            leftArrow = left;
        }
        if(Node->right && Node->right->val == Node->val){
            rightArrow = right;
        }

        max = std::max(max,leftArrow+rightArrow+1);
         return std::max(leftArrow,rightArrow)+1;

    }
    int longestUnivaluePath(TreeNode* root) {

        dfs(root);
        return max> 0 ? max-1 : 0;
    }
};