class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        unordered_map<int, int> res;

        // Use pair<int, int> for {length, right_end}. 
        // greater<pair<int,int>> automatically sorts by the first element (length).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int i = 0;
        for (int q : sortedQueries) {
            // Push valid intervals
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r}); // Now creates a fast pair, not a vector
                i++;
            }

            // Pop expired intervals
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }

            // Save the result
            res[q] = minHeap.empty() ? -1 : minHeap.top().first;
        }

        // Map answers back to original query order
        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = res[queries[j]];
        }
        return result;
    }
};