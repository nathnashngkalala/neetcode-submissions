class Twitter {
public:
    /*
        getNewsFeed
            10 most recent tweet ID
                in user feed (user is following, or user themselves)
                ordered by most recent and least recent
            follow
                user -> follow -> user2
            unfollow
                user -> unfollow -> user2
        can use max heap for most recent, but tricky because
        data structure is combination of both user post and their followers
        sort for every getNewsFeed can work
        Tbh its easier to just sort whenever we get news feed
    */
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timestamp = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp++});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> idToQuery = {userId};
        const unordered_set<int>& followed = following[userId];
        for(const int& id : followed) {
            if(id != userId){
                idToQuery.push_back(id);
            }
        }
        vector<pair<int,int>> tweetsToQuery;
        for(int i = 0; i < idToQuery.size(); ++i) {
            int id = idToQuery[i];
            for(const pair<int,int>& tweetId : tweets[id]) {
                tweetsToQuery.push_back(tweetId);
            }
        }
        sort(tweetsToQuery.begin(), tweetsToQuery.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.second > b.second;
        });
        vector<int> res;
        for(int i = 0; i < tweetsToQuery.size(); ++i) {
            if(res.size() >= 10) {
                break;
            }
            res.push_back(tweetsToQuery[i].first);
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
