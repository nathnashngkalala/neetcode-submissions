class Solution {
public:
    /*
        increasing int[]
        remove dups from nums (in-place)
        return k first k is unique
        so in-place is tricky right
        we have a pointer that denotes the curr unique
        once we find a new one since sorted we know its < before
        so we just swithch ++i to j -> j just go trough n - 1
    */
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j < n; ++j) {
            if(nums[j] > nums[i]) {
                swap(nums[++i], nums[j]);
            }
        }
        return i + 1;
    }
};