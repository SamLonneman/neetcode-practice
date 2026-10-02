class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }
        std::vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        return std::all_of(freq.begin(), freq.end(), [](int f) { return !f; });
    }
};
