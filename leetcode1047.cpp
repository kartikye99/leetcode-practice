class Solution {
public:
    void solve(stack<char>& st, stack<char>& helper) {
        if (st.empty()) {
            return;
        }

        char ch = st.top();
        st.pop();

        solve(st, helper);

        if (!helper.empty() && helper.top() == ch) {
            helper.pop();          // Remove adjacent duplicate
        } else {
            helper.push(ch);
        }
    }

    string removeDuplicates(string s) {
        stack<char> st, helper;

        for (char ch : s) {
            st.push(ch);
        }

        solve(st, helper);

        string ans = "";
        while (!helper.empty()) {
            ans += helper.top();
            helper.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};