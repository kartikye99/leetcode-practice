class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int>st;
        vector<int>ans;
        
        for(int i = 0; i < arr.size(); i++){
            
            
            while(!st.empty() && arr[i] <= st.top() ){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
                
            }
            else{
                ans.push_back(st.top());
            }
            st.push(arr[i]);// own added
        }
        return ans;
    }
};