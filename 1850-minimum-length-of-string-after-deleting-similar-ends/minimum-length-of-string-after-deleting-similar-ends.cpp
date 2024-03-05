class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start < end && s[start] == s[end]) {
            char ch = s[start];
            while (start <= end && s[start] == s[end]) {
                start++;
            }
            while (start <= end && s[end] == ch) {
                end--;
            }
        }
        return end - start + 1;
    }
};