class Solution {
public:
    /*
        []int in increasing order
        return 1 indexed of two numbers so they add up to target
        i1 < i2, so you just need to find 2 indexes added to target
        using extra space like a complement map is the easiest 
        basically you find the number, but to be constant space its trickier 
        [1,2,3,4], target = 3
        we can use two pointers start l = 0, r = n -1 
        1 + 4 = 5 > 3 means we need a smaller number, best chance is decrese r
        the key here is actually the array is sorted...
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n -1;   
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum == target) {
                return {l + 1, r + 1};
            } else if(sum > target) {
                --r;
            } else {
                ++l;
            }
        }   
        return vector<int>();
    }
};
