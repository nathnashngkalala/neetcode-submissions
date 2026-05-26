class Solution {
public:
    /*
        just usee counter
    */
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int n = nums.size();
        for(int x : nums) {
            ++counter[x];
            if(counter[x] > n / 2) {
                return x;
            }
        }
        return -1;
    }
};