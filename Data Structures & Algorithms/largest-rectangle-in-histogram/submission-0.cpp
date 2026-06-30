class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            leftsmall[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            rightsmall[i] = st.empty() ? n-1 : st.top() - 1;
            st.push(i);
        }
        int maxArea = 0;
        for(int i = 0;i<n;i++){
            int width = rightsmall[i] - leftsmall[i] + 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};
