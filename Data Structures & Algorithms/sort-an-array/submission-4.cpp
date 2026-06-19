class Solution {
public:
    vector<int> merge(vector<int>& l, vector<int>& r) {
        vector<int> res;
        int i = 0, j = 0;
        while(i < l.size() && j < r.size()) {
            if(l[i] <= r[j]) {
                res.push_back(l[i++]);
            } else {
                res.push_back(r[j++]);
            }
        }
        while(i < l.size()) {
            res.push_back(l[i++]);
        }
        while(j < r.size()) {
            res.push_back(r[j++]);
        }
        return res;
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums;
        }
        int mid = nums.size() / 2;
        vector<int> l(nums.begin(), nums.begin() + mid);
        vector<int> r(nums.begin() + mid, nums.end());
        vector<int> sortedL = sortArray(l);
        vector<int> sortedR = sortArray(r); 
        return merge(sortedL, sortedR);
    }
};