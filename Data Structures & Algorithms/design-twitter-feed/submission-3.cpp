class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> usr_tweet;
    unordered_map<int, unordered_set<int>> usr_follow;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        usr_tweet[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // 給 usr1
        // 1. 找 usr_tweeet[1] 有他發過的文
        // 2. 找 usr_follow[1] 有他追蹤的人
        // 3. 遍歷 set，一個一個看他們發的文
        vector<int> res;
        // maxheap 存 {time, tweetid}}
        priority_queue<pair<int, int>> maxheap;
        for(auto& p : usr_tweet[userId]){
            maxheap.push({p.first, p.second});
        }
        for(int u : usr_follow[userId]){
            for(auto& p : usr_tweet[u]){
                maxheap.push({p.first, p.second});
            }
        }
        while(!maxheap.empty() && res.size() < 10){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        usr_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        usr_follow[followerId].erase(followeeId);
    }
};
