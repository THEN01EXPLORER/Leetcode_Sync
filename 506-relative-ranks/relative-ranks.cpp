class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;

        // Sort scores from highest to lowest
        sort(sorted.rbegin(), sorted.rend());

        // score -> rank
        unordered_map<int, int> rank;

        for (int i = 0; i < sorted.size(); i++) {
            rank[sorted[i]] = i + 1;
        }

        vector<string> answer;

        for (int s : score) {
            int r = rank[s];

            if (r == 1)
                answer.push_back("Gold Medal");
            else if (r == 2)
                answer.push_back("Silver Medal");
            else if (r == 3)
                answer.push_back("Bronze Medal");
            else
                answer.push_back(to_string(r));
        }

        return answer;
    }
};