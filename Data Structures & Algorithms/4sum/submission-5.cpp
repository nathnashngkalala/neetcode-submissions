class Solution {
public:
    /*
        this is the same as 3 sum we just do it in one other loop...
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n - 3; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n - 2; ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n -1;
                while(k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while(k > j + 1 && k < l && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        while(l < n - 2 && k < l && nums[l] == nums[l + 1]) {
                            --l;
                        }
                    } else if (sum > target) {
                        --l;
                    } else {
                        ++k;
                    }
                }
            }
        }
        return res;
    }
};