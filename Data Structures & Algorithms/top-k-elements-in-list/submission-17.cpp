class Solution {
public:
    /*
        int[] nums, int k
        return k most frequent
        easiest is n log n using max heap
    */
    struct comp {
        bool operator ()(const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        for(int i = 0; i < nums.size(); ++i) {
            ++counter[nums[i]];
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, comp> pq;
        for(auto it : counter) {
            pq.push({it.first, it.second});
        }
        vector<int> res;
        while(k) {
            res.push_back(pq.top().first);
            pq.pop();
            --k;
        }
        return res;
    }
};
