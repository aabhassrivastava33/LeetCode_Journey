class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) return "";

        unordered_set<char> set(s.begin(), s.end());

        for (int i = 0; i < s.length(); i++) {
            if (set.count(tolower(s[i])) && set.count(toupper(s[i]))) {
                continue;
            }
            string s1 = longestNiceSubstring(s.substr(0, i));
            string s2 = longestNiceSubstring(s.substr(i + 1));
            return s1.length() >= s2.length() ? s1 : s2;
        }

        return s;
    }
};