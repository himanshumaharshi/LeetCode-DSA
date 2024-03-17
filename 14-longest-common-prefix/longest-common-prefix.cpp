class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // T.C -> O(n * m), S.C -> O(1)
        string ans = "";
        // loop on first string
        for (int i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i];
            bool match = true;
            // compare this character with all the remaining strings at the same time
            for (int j = 1; j < strs.size(); j++)
            {
                // compare
                if (strs[j].size() < i || ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }
            if (match == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
};