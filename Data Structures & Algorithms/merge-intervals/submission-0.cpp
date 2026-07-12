class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l = 0;
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        for(int r = 1;r<n;r++){
            if(intervals[l][1]>=intervals[r][0]){
                intervals[l][1] = max(intervals[r][1],intervals[l][1]);
            }else{
                l++;
                
                intervals[l] = intervals[r];
                
            }
        }
        intervals.resize(l+1);
        return intervals;
    }
};
