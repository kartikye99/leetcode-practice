class Solution {
public:
    void dfshelper(int city,vector<vector<int>>& isConnected,vector<bool>&isVisited){
        isVisited[city] = true;

        for(int i = 0 ; i<isConnected.size();i++){
            //if cities are connected and neighbour not visited 
            if(isConnected[city][i] == 1 && !isVisited[i]){
                dfshelper(i,isConnected,isVisited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n  = isConnected.size();

        vector<bool> isVisited(n,false);
        int count = 0;

        for(int i = 0 ; i<n;i++){
            if(!isVisited[i]){

                //dfshepler
                dfshelper(i,isConnected,isVisited);
                count++;
            }
        }
        return count;
    }
};