class Solution {
public:
    vector<vector<string>> res;

    // Function to check if a substring s[i..j] is a palindrome
    bool ispal(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // function to generate all possible palindrome partitions
    void helper(string& s, int start, vector<string>& current) {
        if (start == s.size()) {
            res.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (ispal(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                helper(s, end + 1, current);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;
        helper(s, 0, current);
        return res;
    }
};