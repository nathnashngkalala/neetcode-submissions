class Solution {
public:
    /*
        To get n^2 solution we can sort first and use the first number as our 
        target and use the two pointers to solve it linearly
        nums = [-1,0,1,2,-1,-4]
        i = 0
        target is -1 -> j = i + 1 and k = n - 1
        we itterate i from 0 to n - 2
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n - 2; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n -1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while(j > i + 1 && j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while(k < n - 2 && j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                } else if (sum > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
};
