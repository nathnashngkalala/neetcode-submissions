class Solution {
public:
    /*
        int[] nums, int k
        return k most frequent
        easiest is n log n using max heap, antoher way is using bucket sort
        basically you make an array of maxElem size where maxElem is the largest number in nums
        then you use that as counter its the same as counting alphabet
        mem wise its O(maxElem), but can do linear time solution instead of n log k
        but the numbers are [-1000, 1000] so we need to do some smart indexing
        but this sucks we can do a freq map where it counts and we exhaust all the largest ones first
        [1,2,2,3,3,3]
        {{1,1}{2,2}{3,3}} -> min freq is [1,3], at worst something is happening 0 times
        so we make a 2d array of [freq][numbers] -> then its [0, maxFreq]
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxFreq = 0;
        unordered_map<int,int> counter;
        for(int x : nums) {
            ++counter[x];
            maxFreq = max(maxFreq, counter[x]);
        }
        vector<vector<int>> bucket(maxFreq + 1);
        for(auto it: counter) {
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        int curr = bucket.size() - 1;
        while(k) {
            if(bucket[curr].size() <= 0) {
                --curr;
                continue;
            }
            for(int i = 0; i < bucket[curr].size(); ++i) {
                if(k <= 0) {
                    break;
                }
                res.push_back(bucket[curr][i]);
                --k;
            }
            --curr;
        }
        return res;
    }
};
