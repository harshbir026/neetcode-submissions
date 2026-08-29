class Solution {
public:
    vector<int> toposort(vector<vector<int>>& adj) {
        int V = adj.size(); 
        vector<int> inDegree(V, 0);
        
        for (int i = 0; i < V; i++) {
            for (auto node : adj[i]) {
                inDegree[node]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto adjNode : adj[node]) {
                inDegree[adjNode]--;
                if (inDegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        return topo;
    }

    string foreignDictionary(vector<string> &words) {
        
        vector<bool> exists(26, false);
        int V = 0;
        
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                if (!exists[c - 'a']) {
                    exists[c - 'a'] = true;
                    V++;
                }
            }
        }
        
        
        vector<vector<int>> adj(26);
        
        for (int i = 1; i < words.size(); i++) {
            string s1 = words[i-1];
            string s2 = words[i];
            int len = min(s1.size(), s2.size());
            
            if(s1.size() > s2.size() && s1.substr(0,len) == s2.substr(0,len)){
                return {};
            }
            // Find the first differing character to create a directed edge
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        // Step 3: Run Topological Sort on all 26 letters
        vector<int> topo = toposort(adj);
        
        // Step 4: Construct the final string using ONLY the existing letters
        string res = "";
        for (int i = 0; i < topo.size(); i++) {
            if (exists[topo[i]]) {
                res += (topo[i] + 'a');
            }
        }
        
        // If the result string doesn't have all the unique letters, there was a cycle
        if (res.size() != V) return "";
        
        return res;
    }
};