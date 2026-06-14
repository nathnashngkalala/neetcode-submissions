class Solution {
public:
    /*
        have unsorted int[] nums
        return smallest positive int that is not in nums
        integers are not unique 
        linear time and in place
        you have max and min we can find the max and min
        when we itterate we know:
            1. if something is positive/ negative
            2. we know the exact previous/ next # (if all the space is linear)
                a. only if within bounds
        use the array itself as hashtable
        so for negatives/ zero we ignore 
        so we just swap a number nums[i] to nums[nums[i]-1]
        after that we go trough the array for every number 
        >0 that is nums[i] != i + 1, i + 1 is our missing number
    */
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};