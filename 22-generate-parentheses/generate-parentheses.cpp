class Solution {
private:
    void backtrack(int pos, int open, int close, int n, string& current, vector<string>& result) {
        // Base case: full string built
        if (pos == 2 * n) {
            result.push_back(current);
            return;
        }

        // Option 1: Place '('
        if (open < n) {
            current[pos] = '(';
            backtrack(pos + 1, open + 1, close, n, current, result);
        }

        // Option 2: Place ')'
        if (close < open) {
            current[pos] = ')';
            backtrack(pos + 1, open, close + 1, n, current, result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current(2 * n, ' '); // Pre-allocate fixed length buffer
        backtrack(0, 0, 0, n, current, result);
        return result;
    }
};