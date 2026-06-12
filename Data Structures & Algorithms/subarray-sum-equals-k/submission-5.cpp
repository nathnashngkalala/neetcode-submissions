class Solution {
public:
    /*
        To do this linearly 
        we need to use prefixSum + counting
        at ith element we need to know at O(1) how many subarray 
        ending at i that result in k 
        means that if there is a number where sum - k exist 
        we add how many that appeared
        nums = [2,-1,1,2], k = 2
        {{2,2}{1,1},{4,1}}
    */
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumMap;
        sumMap[0] = 1;
        int sum = 0;
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            int complement = sum - k;
            if(sumMap.count(complement)) {
                res += sumMap[complement];
            }
            ++sumMap[sum];
        }
        return res;
    }
};