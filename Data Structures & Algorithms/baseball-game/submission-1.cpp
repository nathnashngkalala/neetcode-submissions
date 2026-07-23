class Solution {
public:
    /*
        return sum of records in operations array
        use a stack and evaluate imidately when D and C appears
        for + we just save a temp
        ["1","2","+","C","5","D"]
        [1,2,5,10]
    */
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int n = operations.size();
        for(int i = 0; i < n; ++i) {
            string curr = operations[i];
            if(curr == "+") {
                int j = scores.size() - 1;
                scores.push_back(scores[j] + scores[j - 1]);
            } else if (curr == "C") {
                scores.pop_back();
            } else if (curr == "D"){
                int j = scores.size() - 1;
                scores.push_back( scores[j] * 2);
            } else {
                scores.push_back(stoi(curr));
            }
        }
        return std::accumulate(scores.begin(), scores.end(), 0);
    }
};