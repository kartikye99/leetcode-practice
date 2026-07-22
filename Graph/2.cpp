class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        //create a visites array to keep track of visited nodes
        //create a queue for bfs traversal 
        //start from any nodes (let say 0), mark it visited and push it in the queue 
        //while(!q.empoty){
            //remove the front node add it to anser 
            // visit all unvisited neighbours, mark them visited and push them in queue
            //return the BFS traversal output
            
            int V = adj.size();
            queue<int>q;
            vector<int>bfsresult; // store bfs traversal
            vector<bool> visited(V, false);
            
            // start bfs for node 0
            q.push(0);
            visited[0] = true;
            //continue untill all reachable nodes are visited 
            while(!q.empty()){
                int front = q.front();
                q.pop();
                //add current node in answer
                bfsresult.push_back(front);
                
                //visit all neighbours of current node
                for(auto i : adj[front]){
                    if(!visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
                
            }
        
            return bfsresult;
    }
};