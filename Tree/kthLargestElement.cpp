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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        vector<long long>ans;
        if(root==nullptr){
            return 0;
        }
        q.push(root);
        while(!q.empty()){
            int levelsize = q.size();
            long long sum = 0;

            for(int i  = 0; i<levelsize; i++){
                TreeNode* front = q.front();
                q.pop();
                sum+=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);

            }

            ans.push_back(sum);
        }
         if (k > ans.size())
            return -1;
        sort(ans.begin(),ans.end(), greater<>());
        return ans[k-1];
    }
};