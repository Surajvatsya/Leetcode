class Twitter
{
    public:
        int t;

    unordered_map<int, vector<pair<int, int>>> mp;
    unordered_map<int, set < int>> user_follow;

    Twitter()
    {
        t = 0;
    }

    void postTweet(int userId, int tweetId)
    {


        mp[userId].push_back({ ++t,
            tweetId });
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq;
        vector<pair<int, int>> v = mp[userId];
        for (auto &x: v)
        {
            pq.push(x);
        }
        auto &target = user_follow[userId];
        for (auto &x: target)
        {
            vector<pair<int, int>> v1 = mp[x];
            for (auto &x: v1)
            {
                pq.push(x);
            }
        }
        int mn = 10;

       if(pq.size()<10)
           mn=pq.size();
        vector<int> ans;
        while (mn--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        user_follow[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        user_follow[followerId].erase(followeeId);
    }
};

/**
 *Your Twitter object will be instantiated and called as such:
 *Twitter* obj = new Twitter();
 *obj->postTweet(userId,tweetId);
 *vector<int> param_2 = obj->getNewsFeed(userId);
 *obj->follow(followerId,followeeId);
 *obj->unfollow(followerId,followeeId);
 */