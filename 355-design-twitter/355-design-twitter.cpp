class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    vector<pair<int, int>> tweets;//first is twitter id and second is tweet id
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(pair<int,int>(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int i=0, n=tweets.size(), j=n-1;
        while(i<10 and j>-1){
            if(tweets[j].first==userId or following[userId].find(tweets[j].first)!=following[userId].end()){
                res.push_back(tweets[j].second);
            i++;
            }
            j--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */