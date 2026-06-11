class Solution {
public:
    /*
        int[] nums, and int k
        return total # of subarrays whose sum == k
        brute force is n^2 because we find all subarrays
        if we sort 
        nums = [2,-1,1,2]
        prefixSum + hashmap
        [2,1,2,4] 
        [4,2,3,2] 
        when I get to 2 complement is 0 so I need 0 more to get that 
        its included
        if I get to -1 
            -1 + x = 2 -> I neeed 3 
        so if there is complement >= 0 in the prefixSum its added
    */
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCounter;
        sumCounter[0] = 1;
        int n = nums.size();
        int sum = 0;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            res += sumCounter[sum - k];
            ++sumCounter[sum];
        }
        return res;
    }
};