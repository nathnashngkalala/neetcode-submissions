class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int x : nums) {
            if(hashSet.count(x)) {
                return true;
            }
            hashSet.insert(x);
        }
        return false;
    }
};