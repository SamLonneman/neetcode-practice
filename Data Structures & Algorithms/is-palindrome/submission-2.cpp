class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.length() - 1;
        while (front < back)
        {
            while (front < back && (s[front] < 'a' || s[front] > 'z') && (s[front] < 'A' || s[front] > 'Z') && (s[front] < '0' || s[front] > '9'))
            {
                front++;
            }
            while (front < back && (s[back] < 'a' || s[back] > 'z') && (s[back] < 'A' || s[back] > 'Z') && (s[back] < '0' || s[back] > '9'))
            {
                back--;
            }
            if (s[front] >= 'A' && s[front] <= 'Z')
            {
                s[front] += 'a' - 'A';
            }
            if (s[back] >= 'A' && s[back] <= 'Z')
            {
                s[back] += 'a' - 'A';
            }
            if (s[front] != s[back])
            {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};
