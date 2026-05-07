class Solution {
public:
    /*
        we use stack to decode 
        we have 3 cases we start always with number 
        and then we have the eventual repeated string
        so once we see a ] we need to evaluate 
        [ means we repeated the currString x times
        number we just add to number letter to currString
        Input: s = "2[a3[b]]c"
        count = 2
        curr = abbbabbbc
        [c]
    */
    string decodeString(string s) {
        int count = 0;
        string curr = "";
        stack<pair<int, string>> currStack;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            // cout << count << " " << curr << endl;
            if(isdigit(c)) {
                count = (count * 10) + (c - '0');
            } else if (s[i] == '[') {
                currStack.push({count, curr});
                count = 0;
                curr = "";
            } else if (s[i] == ']') {
                auto [counter, prev] = currStack.top(); 
                currStack.pop();
                string repeated = "";
                for(int i = 0; i < counter; ++i) {
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