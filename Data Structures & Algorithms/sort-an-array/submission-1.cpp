class Solution {
public:
    /*
        merge sort man 
    */
    vector<int> merge(vector<int> l, vector<int> r) {
        vector<int> res;
        int i = 0, j = 0;
        while(i < l.size() && j < r.size()) {
            if(l[i] <= r[j]) {
                res.push_back(l[i]);
                ++i;
            } else {
                res.push_back(r[j]);
                ++j;
            }
        }
        while(i < l.size()) {
            res.push_back(l[i]);
            ++i;
        }
        while(j < r.size()) {
            res.push_back(r[j]);
            ++j;
        }
        return res;
    }
    vector<int> mergeSort(vector<int> arr) {
        if(arr.size() <= 1) {
            return arr;
        }
        int mid = arr.size() / 2;
        vector<int> l(arr.begin(), arr.begin() + mid);
        vector<int> r(arr.begin() + mid, arr.end());
        vector<int> sortedL = mergeSort(l);
        vector<int> sortedR = mergeSort(r);
        return merge(sortedL,sortedR);
    }
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }
};