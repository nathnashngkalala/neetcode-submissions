class Solution {
public:
    /*
        int[], people is the weight of person
        infinite boats, max weight of limit
        each boat can carry most 2 
        minimize number of boats needed, to minimize 
        I need to put the heaviest with the smallest
        if I put two heaviest they will overflow and need another boat
        sorting and two pointers is n log n
        counting is n in time but n in space
        [1,3,2,3,2]
        [0,1,2,2]
        at most someone is <= limit right
        so if so then we always use the left and see if we can fit right 
        if not then we dont have what we need 
    */
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> counter(limit + 1, 0);
        for(int x : people) {
            ++counter[x];
        }
        int l = 1, r = limit;
        int res = 0;
        while(l <= r) {
            while(l <= r && counter[l] <= 0) ++l;
            while(l <= r && counter[r] <= 0) --r;
            if(l > r) break;
            ++res;
            --counter[r];
            if(l + r <= limit) {
                --counter[l];
            }
        }
        return res;
    }
};