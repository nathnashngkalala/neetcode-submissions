class Solution {
public:
    /*
        numbers[] increasing order
        return two numbers that add up to target
        i1 != i2, have to be in place
        Number is sorted so give l and r they are at the end
        we can see if we need to increase or decrease to find target
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if(numbers[l] + numbers[r] > target) {
                --r;
            } else if (numbers[l] + numbers[r] < target) {
                ++l;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {};
    }
};
