class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                // closing brackets
                if(!st.empty())
                {
                    char topCh = st.top();
                    if(ch == ')' && topCh == '(') 
                    { // matching brackets found
                        st.pop();
                    }
                    else if(ch == ']' && topCh == '[') 
                    { // matching brackets found
                        st.pop();
                    }
                    else if(ch == '}' && topCh == '{') 
                    { // matching brackets found
                        st.pop();
                    }
                    else 
                    { // brackets not matching
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};