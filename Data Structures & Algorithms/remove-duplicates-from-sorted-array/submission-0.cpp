class Solution {
public:
    /*
        integer array []
        sorted in decreasing order
        remove duplicates in palce 
    */
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        int i = 0;
        for(int j = 0;  j < n; ++j) {
            if(nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};