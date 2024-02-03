class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int start = 0;
        while (start < s.length())
        {
            if(ans.length() > 0)
            {
                if(ans[ans.length() - 1] == s[start])
                {
                    ans.pop_back();
                }
                else
                {
                    ans.push_back(s[start]);
                }
            }
            else
            {
                ans.push_back(s[start]);
            }
            start++;
        }
        return ans;
    }
};