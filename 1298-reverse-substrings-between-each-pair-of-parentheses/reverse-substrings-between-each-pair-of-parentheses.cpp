class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(result.size());
            else if (s[i] == ')') {
                // reverse
                reverse(result.begin() + st.top(), result.end());
                st.pop();
            }
            else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};