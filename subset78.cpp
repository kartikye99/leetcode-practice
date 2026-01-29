class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int total = 1 << n;   // 2^n subsets

        for (int i = 0; i < total; i++) {
            vector<int> ans;   // ek subset

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    ans.push_back(nums[j]);
                }
            }

            result.push_back(ans);
        }

        return result;
    }
};
