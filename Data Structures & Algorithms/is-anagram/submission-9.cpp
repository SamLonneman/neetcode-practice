class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> hashTable(26, 0);
        for (char c : s)
        {
            hashTable[c - 'a']++;
        }
        for (char c : t)
        {
            if (!hashTable[c - 'a'])
            {
                return false;
            }
            hashTable[c - 'a']--;
        }
        for (int f : hashTable)
        {
            if (f)
            {
                return false;
            }
        }
        return true;
    }
};
