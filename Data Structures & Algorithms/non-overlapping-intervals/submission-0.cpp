class Solution {
public:
    bool static comp(vector<int>& a ,vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> res;
        int cnt= 0;
        res.push_back(intervals[0]);
        for(int i = 1;i<n;i++){
            if(res.back()[1]>intervals[i][0]){
                cnt++;
            }else{
                res.push_back(intervals[i]);
            }
        }
        return cnt;
    }
};
