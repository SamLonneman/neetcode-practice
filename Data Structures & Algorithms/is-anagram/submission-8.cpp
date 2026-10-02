class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for (char c : s)
        {
            m[c]++;
        }
        for (char c : t)
        {
            if (!m.contains(c) || !m[c])
            {
                return false;
            }
            m[c]--;
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second)
            {
                return false;
            }
        }
        return true;
    }
};
