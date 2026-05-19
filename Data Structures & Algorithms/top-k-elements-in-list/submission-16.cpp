class Solution {
public:
    /*
        have int [] and k
        return k most frequent elements
        can use heap or bucket sort
        heap is n log n, bucket sort is n
        bucket sort is we know the range of numbers
        so the space is O(m) where m is max range number
        we then need to return the numbers that appear 
        most, we count the numbers put it into the bucket
        [1,2,2,3,3,3]
        [{1,1},{2,2},{3,3}] -> then we need to return the k frequent element
        so now we have a frequency array -> of size nums.size() upper bound when
        all # are the same
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int,int> counter;
        for(int x : nums) {
            ++counter[x];
        }
        for(auto it : counter) {
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i = bucket.size() - 1; i >= 0; --i) {
            for(int j = 0; j < bucket[i].size(); ++j) {
                res.push_back(bucket[i][j]);
                if(res.size() == k) {
                    return res;
                }
            }
        }
        return {};
    }
};
