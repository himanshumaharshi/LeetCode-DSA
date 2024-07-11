class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        // Stack to store the positions of '('
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(result.size()); // Store the position of '(' in the result string
            else if (s[i] == ')') {
                // Reverse the substring from the position of the last '(' to the current end of the result string
                reverse(result.begin() + st.top(), result.end());
                // Remove the position of the last '(' from the stack
                st.pop();
            } else {
                // Append current character to the result
                result.push_back(s[i]);
            }
        }
        return result;
    }
};