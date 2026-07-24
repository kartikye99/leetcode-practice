class Solution {
public:
    void dfs(int r , int c , vector<vector<int>>&image, int original , int newcolor){
        int n = image.size();
        int m = image[0].size();
        if(r<0 || r>=n || c<0 || c>=m){
            return;
        }
        if(image[r][c]!=original){
            return;
        }
        image[r][c] = newcolor;   
        // top
        dfs(r-1,c,image,original,newcolor);
        // bottom
        dfs(r+1,c,image,original,newcolor);
        //left
        dfs(r,c-1,image,original,newcolor);
        //right
        dfs(r,c+1,image,original,newcolor);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original == color) return image;
        dfs(sr,sc,image,original,color);

        return image;
    }
};