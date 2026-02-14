class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int > st;
        // vector<int> ans;
        for(int i = 0;i<asteroids.size();i++){
            bool d = false;
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                if(st.top()<-asteroids[i]){
                    st.pop();
                }
                else if(st.top()==-asteroids[i]){
                    st.pop();
                    d = true;
                    break;
                }
                else{
                        d = true;
                        break;
                }
            }
            if(d==false){
                st.push(asteroids[i]);
            }
        }

        vector<int> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};