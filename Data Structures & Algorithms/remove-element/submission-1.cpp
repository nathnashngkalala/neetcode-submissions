class Solution {
public:
    /*
        int[] nums and int val
        remove all occurances of val (in place)
        we have a pointer if its not val its part of nums if == val we increment
        i and then next we copy the value we want to include in k agaijn
    */
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};