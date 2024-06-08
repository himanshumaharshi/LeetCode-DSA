class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57) {
                continue;
            }
            else if (s[i] >= 65 && s[i] <= 90) {
                // convert uppercase into lowercase
                s[i] = s[i] + ('a' - 'A');
            }
            else {
                s.erase(i, 1);
                i--;
            }
        }
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};