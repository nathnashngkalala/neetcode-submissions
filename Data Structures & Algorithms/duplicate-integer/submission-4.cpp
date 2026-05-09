class Solution {
public:
    /*
        return value if appear more than once, easy of we use extra space
        if sorted then we just check the one before for n time soln
    */
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
};