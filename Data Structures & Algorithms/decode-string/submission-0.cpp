class Solution {
public:
    /*
        so you use a stack and basically build the string up along the way
        [{1,"abbbabbbb"},{1,c}]

    */
    string decodeString(string s) {
        int n = s.size();
        int currNum = 0;
        string curr = "";
        stack<pair<int, string>> simStack;
        for(int i = 0; i < n; ++i) {
            if(isdigit(s[i])) {
                currNum = (currNum * 10) + (s[i] - '0');
            } else if (s[i] == '[') {
                simStack.push({currNum, curr});
                curr = "";
                currNum = 0;
            } else if (s[i] == ']') {
                auto [count, prev] = simStack.top();
                simStack.pop();
                string repeated = "";
                for(int i = 0; i < count; ++i) {
                    repeated += curr;
                }
                curr = prev + repeated;

            } else {
                curr += s[i];
            }
        }
        return curr;
    }
};