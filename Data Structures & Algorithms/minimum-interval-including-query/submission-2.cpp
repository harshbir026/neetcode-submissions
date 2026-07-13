class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        sort(intervals.begin(), intervals.end());

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        unordered_map<int, int> res;

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int i = 0;
        for (int q : sortedQueries) {
            
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r}); 
                i++;
            }

            
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }

            
            res[q] = minHeap.empty() ? -1 : minHeap.top().first;
        }

        
        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = res[queries[j]];
        }
        return result;
    }
};