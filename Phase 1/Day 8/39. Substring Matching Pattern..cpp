// LeetCode: https://leetcode.com/problems/substring-matching-pattern/description/

// My Code:
class Solution {
public:
    bool hasMatch(string s, string p) {

        int index = 0;
        for (int i = 0; i < p.size(); i++) {
            char ch = p[i];
            if (ch == '*') {
                index = i;
                break;
            }
        }

        string left = p.substr(0, index);
        string right = p.substr(index + 1, p.size());

        int i = s.find(left);
        int j = s.rfind(right);// means find the right most substring

        return i != -1 && j != -1 && i + left.size() <= j;
    }
};
