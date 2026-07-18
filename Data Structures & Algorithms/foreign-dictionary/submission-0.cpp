class Solution {
public: 
    // Changed DFS to return a boolean: true if a cycle is detected, false otherwise
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, stack<int>& st, vector<vector<int>>& adj) {
        visited[node] = 1;
        pathVisited[node] = 1; // Mark node in the current DFS path
        
        for(auto adjNode : adj[node]) {
            if(!visited[adjNode]) {
                if(dfs(adjNode, visited, pathVisited, st, adj)) return true;
            } 
            // If the node is already visited AND is in the current path, we found a cycle
            else if(pathVisited[adjNode]) {
                return true; 
            }
        }
        
        pathVisited[node] = 0; // Remove from current path when backtracking
        st.push(node);
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        unordered_set<char> unique;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                unique.insert(words[i][j]);
            }
        }
        
        vector<vector<int>> adj(26);
        for(int i = 1; i < words.size(); i++){
            string s1 = words[i-1];
            string s2 = words[i];
            
            int len = min(s1.length(), s2.length());
            
            // CORRECTED PREFIX CHECK: 
            // If s1 is longer than s2, and the beginning of s1 is exactly s2, it's invalid.
            if(s1.length() > s2.length() && s1.substr(0, len) == s2) {
                return "";
            }
            
            for(int j = 0; j < len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> visited(26, 0);
        vector<int> pathVisited(26, 0); // Needed for cycle detection
        stack<int> st;
        
        for(int i = 0; i < 26; i++){
            // CORRECTED UNIQUE CHECK: check for i + 'a'
            if(!visited[i] && unique.find(i + 'a') != unique.end()){
                // If DFS detects a cycle, return empty string
                if(dfs(i, visited, pathVisited, st, adj)) {
                    return "";
                }
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top() + 'a';
            st.pop();
        }
        return ans;
    }
};