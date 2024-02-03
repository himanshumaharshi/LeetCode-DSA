class Solution {
public:
    // method 2
    int expandAroundIndex(string str, int left, int right)
    {
        int count = 0;
        // jb taq match karega tb taq count increment kardo and left-- and right++ kardo
        while (left >= 0 && right < str.length() && str[left] == str[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }


    int countSubstrings(string str) {
        int count = 0;
        // method 1
        // for (int i = 0; i < str.length(); i++)
        // {
        //     for (int j = i; j < str.length(); j++)
        //     {
        //         if (str[i] == str[j])
        //         {
        //             count++;
        //         }
        //     }
        // }

        // method 2
        for (int center = 0; center < str.length(); center++)
        {
            // odd
            int oddAns = expandAroundIndex(str, center, center);
            count += oddAns;
            // even
            int evenAns = expandAroundIndex(str, center, center + 1);
            count += evenAns;
        }
        return count;
    }
};