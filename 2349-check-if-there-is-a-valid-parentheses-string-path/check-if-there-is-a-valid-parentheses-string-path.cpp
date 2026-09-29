class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total number of characters must be even
        if ((m + n - 1) % 2 == 1)
            return false;

        // A valid parentheses string must start with '('
        if (grid[0][0] == ')')
            return false;

        // A valid parentheses string must end with ')'
        if (grid[m - 1][n - 1] == '(')
            return false;

        // dp[i][j][b] = can we reach (i,j) with balance b?
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        // Start at (0,0)
        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= m + n - 1; balance++) {

                    int newBalance = balance;

                    if (grid[i][j] == '(')
                        newBalance++;
                    else
                        newBalance--;

                    // Balance can never be negative
                    if (newBalance < 0)
                        continue;

                    bool possible = false;

                    // Come from top
                    if (i > 0 && dp[i - 1][j][balance])
                        possible = true;

                    // Come from left
                    if (j > 0 && dp[i][j - 1][balance])
                        possible = true;

                    if (possible)
                        dp[i][j][newBalance] = true;
                }
            }
        }

        // Valid string must finish with balance 0
        return dp[m - 1][n - 1][0];
    }
};