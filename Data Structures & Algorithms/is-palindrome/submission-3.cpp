class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            while (left < right && !isAlphanumeric(s[left]))
            {
                left++;
            }
            while (left < right && !isAlphanumeric(s[right]))
            {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isAlphanumeric(char c)
    {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }
};
