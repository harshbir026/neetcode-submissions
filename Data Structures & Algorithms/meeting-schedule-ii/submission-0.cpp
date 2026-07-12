#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        if (intervals.empty()) return 0;

        
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) { 
                 return a.start < b.start; 
             });

        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        
        minHeap.push(intervals[0].end);

        
        for (int i = 1; i < intervals.size(); i++) {
            
            
            if (intervals[i].start >= minHeap.top()) {
                minHeap.pop(); 
            }
            
            
            minHeap.push(intervals[i].end);
        }

       
        return minHeap.size();
    }
};