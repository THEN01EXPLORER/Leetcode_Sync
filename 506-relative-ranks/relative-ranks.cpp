class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;

        // Push {score, original index}
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        vector<string> answer(score.size());
        int rank = 1;

        while (!pq.empty()) {
            auto [s, index] = pq.top();
            pq.pop();

            if (rank == 1)
                answer[index] = "Gold Medal";
            else if (rank == 2)
                answer[index] = "Silver Medal";
            else if (rank == 3)
                answer[index] = "Bronze Medal";
            else
                answer[index] = to_string(rank);

            rank++;
        }

        return answer;
    }
};