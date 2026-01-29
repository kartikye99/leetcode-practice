class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // ✅ change 1

        set<vector<int>> st;              // ✅ change 2
        int total = 1 << nums.size();

        for (int i = 0; i < total; i++) {
            vector<int> ans;

            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    ans.push_back(nums[j]);
                }
            }
            st.insert(ans);   // duplicates automatically remove
        }

        return vector<vector<int>>(st.begin(), st.end());
        // return st;
    }
};
