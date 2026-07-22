class Solution {
public:
    /*
        for this we can sort using 3 pointers
        we have 3 values right, so we can shift all 0s
        we see to the left and 2 to the right
    */
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, mid = 0, r = n - 1;
        while(mid <= r) {
            if(nums[mid] == 0) {
                swap(nums[mid++], nums[l++]);
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[r--]);
            } else {
                ++mid;
            }
        }
    }
};