class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int maxi = 0;

        // Left to right traversal
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxi = max(maxi, left * 2);
            }
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;

        // Right to left traversal
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxi = max(maxi, right * 2);
            }
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return maxi;
    }
};