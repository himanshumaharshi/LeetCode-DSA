class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int size = s.length();
        int ones = 0;
        for (char &c : s) {
            ones += c == '1' ? 1 : 0;
        }
        string ans = "";
        for (int i = 0; i < size - 1; i++) {
            if (i < ones - 1) {
                ans += "1";
            }
            else {
                ans += "0";
            }
        }
        ans += "1";
        return ans;
    }
};