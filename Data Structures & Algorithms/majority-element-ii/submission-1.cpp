class Solution {
public:
    /*
        have int[] nums of size n
        find all elements that appear > n/3 times
        naive way is count the numbers and see if count > n/3
        linear time solution
    */
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;
        for(int x : nums) {
            ++counter[x];
        }
        int n = nums.size();
        vector<int> res;
        for(auto it: counter) {
            if(it.second > n /3) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};