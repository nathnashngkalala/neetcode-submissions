class Solution {
public:
    /*
        I had a good idea with the optimization fo freq count
        but I actually need to pack the lightest with the heaviest
    */
    int numRescueBoats(vector<int>& people, int limit) {
        int maxPeople = *max_element(people.begin(), people.end());
        vector<int> arr(maxPeople + 1, 0);
        for(int i = 0; i < people.size(); ++i) {
            ++arr[people[i]];
        }
        int l = 1 , r = arr.size() - 1;
        int res = 0;
        while(l <= r) {
            while(l <= r && arr[l] <= 0) {
                ++l;
            }
            while(l <= r && arr[r] <= 0) {
                --r;
            }
            if(l > r) break;
            ++res;
            --arr[r];
            if(l + r <= limit) {
                --arr[l];
            }
        }
        return res;
    }
};