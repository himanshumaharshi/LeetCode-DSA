class Solution {
public:

    void solve(vector<string> &ans, int index, unordered_map<int, string> &mapping, string output, string digits)
    {
        // base case
        if(index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0';
        string value = mapping[digit];
        for(int i = 0; i < value.length(); i++)
        {
            char ch = value[i];
            output.push_back(ch);
            // recursive call
            solve(ans, index + 1, mapping, output, digits);
            // backtrack
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)
        {
            return ans;
        }
        int index = 0;
        string output = "";
        unordered_map<int, string> mapping;
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        solve(ans, index, mapping, output, digits);
        return ans;
    }
};