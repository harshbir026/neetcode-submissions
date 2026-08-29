class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>distance(n+1,1e8);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        distance[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            if(dist > distance[node]) continue;
            for(auto iter : adj[node]){
                int edgeW = iter.second;
                int adjNode = iter.first;
                if( dist + edgeW < distance[adjNode]){
                    distance[adjNode] = dist + edgeW;
                    pq.push({distance[adjNode],adjNode});
                }
            }
        }
        int ans = -1;
        for(int i = 1;i<=n;i++){
            if(distance[i]==1e8){
                return -1;
            }else{
                ans = max(ans,distance[i]);
            }
        }
        return ans;
    }
};
