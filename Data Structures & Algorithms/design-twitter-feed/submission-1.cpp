class Twitter {
public:
    int time ;
    Twitter() {
        time = 1;
    }
    map<int,set<pair<int,int>>> tweets;
    unordered_map<int,set<int>> follows;
    void postTweet(int userId, int tweetId) {
        set<pair<int,int>> myTweets = tweets[userId];
        if(myTweets.size()==10){
            myTweets.erase(myTweets.begin());
        }
        myTweets.insert({time,tweetId});
        tweets[userId] = myTweets;
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        set<int> network = follows[userId];
        network.insert(userId);
        set<pair<int,int>> top10;
        for(auto u : network){
            set<pair<int,int>> myTweets = tweets[u];
            for(pair<int,int> t : myTweets){
                if(top10.size()<10){
                    top10.insert(t);
                }else{
                    pair<int,int> oldest = *top10.begin();
                    if(t.first>oldest.first){
                        top10.erase(top10.begin());
                        top10.insert(t);
                    }
                }
            }
        }
        for(pair<int,int> t : top10){
            feed.push_back(t.second); 
        }
         reverse(feed.begin(), feed.end()); 
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        set<int> network = follows[followerId]; 
        if(network.find(followeeId) != network.end()){ 
            network.erase(network.find(followeeId)); 
            follows[followerId] = network; 
        }
    }
};
