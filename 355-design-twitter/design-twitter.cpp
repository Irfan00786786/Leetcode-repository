#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        if(tweets.count(userId)) {
            for(auto &tweet : tweets[userId]) {
                pq.push(tweet);
                if(pq.size() > 10) pq.pop();
            }
        }

        if(following.count(userId)) {
            for(int followee : following[userId]) {
                if(tweets.count(followee)) {
                    for(auto &tweet : tweets[followee]) {
                        pq.push(tweet);
                        if(pq.size() > 10) pq.pop();
                    }
                }
            }
        }
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(following.count(followerId))
            following[followerId].erase(followeeId);
    }
};