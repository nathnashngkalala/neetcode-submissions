class Solution {
public:
    /*
        return value if appear more than once, easy of we use extra space
        if sorted then we just check the one before for n time soln
    */
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> counter;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(counter.count(nums[i])) {
                return true;
            }
            counter.insert(nums[i]);
        }
        return false;
    }
};