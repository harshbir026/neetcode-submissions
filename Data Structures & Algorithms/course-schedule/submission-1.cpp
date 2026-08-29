class Solution {
public:
    bool dfs(int node, vector<int>& visited,vector<int>& pathVisited,vector<vector<int>>&adj){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto adjNode : adj[node]){
            if(!visited[adjNode]){
                if(dfs(adjNode,visited,pathVisited,adj)) return true;
            }else if(pathVisited[adjNode]){
                return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>visited(n,0);
        vector<int>pathVisited(n,0);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,visited,pathVisited,adj)) return false;
            }
        }
        return true;

    }
};
