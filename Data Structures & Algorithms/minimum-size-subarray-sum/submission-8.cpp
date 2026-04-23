class Solution {
public:
    /*
        nums[], target
        return min length of subarray that sum is >= target
        so we keep growing the window if the sum is < target
        if >= target we srhink, and we evaluate only if >= target
    */
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0 ,r = 0;
        int n = nums.size();
        int res = INT_MAX;
        int sum = 0;
        for(r = 0 ; r < n; ++r) {
            sum += nums[r];
            // cout << l << " " << r << " " << sum << endl;
            while(l <= r && sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l];
                ++l;
            }
            // cout << res << endl;
        }
        return res == INT_MAX ? 0 : res; 
    }
};