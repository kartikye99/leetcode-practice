class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> ans;
         int rows = n;
         int cols = n;
        vector<vector<int>> arr(rows, vector<int>(cols));

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        
        vector<int> store;
        for(int i = 1 ; i<=n*n;i++ ){
            store.push_back(i);
        }
        int l = 0;
        while(top<=bottom && left <= right){

            for(int i = left ; i <=right ; i++){
                arr[top][i]= store[l];
                l++;
            }
            top++;

            for(int i = top ; i <=bottom ; i++){
                arr[i][right]= store[l];
                l++;
            }
            right--;

            if(top<=bottom){
                for(int i = right ; i >=left ; i--){
                    arr[bottom][i]= store[l];
                    l++;
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom ; i>=top ; i--){
                    arr[i][left]= store[l];
                    l++;
                }
                left++;
            }
        }
        return arr;
    }
};