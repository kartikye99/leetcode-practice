class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>left(n) ;
        vector<int>right(n);
        //find previous smaller;
        for(int i = 0 ; i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                left[i]  = -1;
            }
            else{
                left[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // find next smaller elements
        for(int i = n-1 ; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n;
            }
            else{
                right[i]=st.top();
            }

            st.push(i);
        }

        int maxi = 0;

        for(int i = 0 ; i<n;i++){
            int w = right[i] - left[i] -1;
            int area = heights[i] * w;
            maxi = max(maxi,area);
        }

        return maxi;
    }
};