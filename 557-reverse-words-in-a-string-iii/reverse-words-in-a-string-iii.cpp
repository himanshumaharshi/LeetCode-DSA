class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int i = 0;
        int start = 0;
        int j = 0;
        while (i < len)
        {
            int end = 0;
            do
            {
                end = j;
                i++;
                j++;
                if (s[j] == ' ')
                    break;
            } while (j < len);
            while (start < end)
            {
                swap(s[start], s[end]);
                start++;
                end--;
            }
            start = i + 1;
        }
        return s;
    }
};