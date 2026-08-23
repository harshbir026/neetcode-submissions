class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mpp(26,0);
        for(int i = 0 ;i<s.size();i++){
            mpp[s[i]-'a']=i;
        }
        vector<int> res;
        int start = 0;
        int end = 0;
        for(int i = 0;i<s.size();i++){
            end = max(end,mpp[s[i]-'a']);
            if(i==end){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};
