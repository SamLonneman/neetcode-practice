class Solution {
public:
    string encode(vector<string>& strs) {
        std::string encoded;
        for (std::string s : strs)
        {
            encoded += std::to_string(s.length()) + "$" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded;
        int start = 0;
        while (start < s.length())
        {
            int numDigitsInLength = s.find("$", start) - start;
            int length = std::stoi(s.substr(start, numDigitsInLength));
            start += numDigitsInLength + 1;
            decoded.push_back(s.substr(start, length));
            start += length;
        }
        return decoded;
    }
};
