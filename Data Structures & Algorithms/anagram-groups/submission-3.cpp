class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a map from a hashable key string to a vector of anagrams.
        // The key string is constructed using the character frequency table.
        // Thus it is shared bewteen all anagrams of a given word.
        std::unordered_map<std::string, std::vector<std::string>> groups;

        // For each string:
        for (std::string str : strs)
        {
            // Get the character frequency table.
            std::vector<int> freq(26, 0);
            for (char c : str)
            {
                freq[c - 'a']++;
            }

            // Encode the character frequency table into a key string.
            std::string key;
            for (int f : freq)
            {
                key += std::to_string(f) + '#';
            }

            // Add the word into the list with the given key string.
            groups[key].push_back(str);
        }

        // Combine all groups into a single container and return.
        std::vector<std::vector<std::string>> result;
        for (auto it = groups.begin(); it != groups.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};
