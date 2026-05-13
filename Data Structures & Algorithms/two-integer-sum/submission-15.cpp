class Solution {
public:
    /*
        so we want to return indicies that reaches the target
        brute force is n^2 and checke every pair but if we 
        know each number index based on value if we see the other
        we can count the complement if it exist we have the answer
        this is a O(n) solution, so the integers arent unique which is interesting
        means that the first can have the same value we can just go trough it right
        once we do if i != j is enough to check, so we just record the smallest index?
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indexMap;
        for(int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if(!indexMap.count(x)) {
                indexMap[x] = i;
            }
        }
        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            // cout << complement << endl;
            if(indexMap.count(complement) && indexMap[complement] != i) {
                return {min(i, indexMap[complement]), max(i, indexMap[complement])};
            }
        }
        return {-1,-1};
    }
};
