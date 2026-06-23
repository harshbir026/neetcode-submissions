class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mpp;
    
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& values = mpp[key]; // & because i don need to modify values , just want to read it
        int left = 0;
        int right = values.size()-1;
        string res = "";
        while(left<=right){
            int mid = (left + right)/2;
            if(values[mid].second<=timestamp){
                res = values[mid].first;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
};
