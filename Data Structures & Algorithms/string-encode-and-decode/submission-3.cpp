class Solution {
public:
    string encode(vector<string>& strs) {
        std::string result;
        for (std::string str : strs)
        {
            result += std::to_string(str.length()) + "$" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        int start = 0;
        int size = 0;
        while (start < s.length())
        {
            int numDigits = s.find("$", start) - start;
            size = std::stoi(s.substr(start, numDigits));
            start += numDigits + 1;
            result.push_back(s.substr(start, size));
            start += size;
        }
        return result;
    }
};
