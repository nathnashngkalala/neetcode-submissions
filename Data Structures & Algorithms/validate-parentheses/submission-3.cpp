class Solution {
public:
    /*
        Have a string s, valid iff
        every open is closed
        open is closed by correct order
        I think can greedily close when we see open add to stack
        if see close match with the top and if false we return if empty return true
    */
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] =='[' || s[i] == '{') {
                st.push(s[i]);
            } else if(st.size() > 0) {
                if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else if(s[i] == '}' && st.top() == '{') {
                    st.pop();
                } else if(s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return st.size() == 0;
    }
};
