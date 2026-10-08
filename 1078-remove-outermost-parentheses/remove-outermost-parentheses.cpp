class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0, right = 0;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                left++;

                if (left != right + 1) {
                    ans += s[i];
                }
            }
            else {
                right++;

                if (left != right) {
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};